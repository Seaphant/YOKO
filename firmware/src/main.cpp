/**
 * YOKO — Main firmware entry point (Arduino framework on ESP32)
 *
 * Loop priority order:
 *   1. Safety — kill motors immediately on over-current
 *   2. Calibration — run homing state machine until all fingers indexed
 *   3. Limit enforcement — clamp duty to homing-learned limits
 *   4. Sensors — read FSR fingertips, apply grip-stop
 *   5. Motors — ramp PWM outputs toward targets
 *   6. Telemetry — periodic debug output
 *   7. Serial commands — process incoming commands
 */

#include <Arduino.h>
#include "config.h"
#include "motor_control.h"
#include "calibration.h"
#include "safety.h"
#include "sensors.h"
#include "logging.h"
#include "serial_cmd.h"

static unsigned long last_tick;
static unsigned long telemetry_timer;

/* Telemetry output interval */
static const unsigned long TELEMETRY_INTERVAL_MS = 500;

void setup(void) {
  logging_banner();

  motor_control_init();
  safety_init();
  sensors_init();
  calibration_init();
  serial_cmd_init();

  logging_state("boot_complete");

  calibration_start_homing();

  last_tick = millis();
  telemetry_timer = millis();
}

void loop(void) {
  unsigned long now = millis();
  if (now - last_tick < LOOP_INTERVAL_MS) return;
  last_tick = now;

  /* 1. Safety: check bus current, latch fault if over threshold */
  safety_update();
  if (safety_in_fault()) {
    motor_control_stop_all();
    return;
  }

  /* 2. Calibration: run homing until complete */
  calibration_update();
  if (!calibration_is_ready()) {
    motor_control_update();
    return;
  }

  /* 3. Enforce calibration limits on all active targets */
  for (int i = 0; i < FINGER_COUNT; i++) {
    int limit = calibration_get_limit(i);
    int duty  = motor_control_get_duty(i);
    if (duty > limit) {
      motor_control_set_duty(i, limit);
    }
  }

  /* 4. Sensors: read FSR, enforce grip-stop */
  sensors_update();
  if (sensors_grip_stop_triggered()) {
    for (int i = 0; i < FINGER_COUNT; i++) {
      if (sensors_read_fsr(i) >= FSR_GRIP_STOP_THRESHOLD) {
        int held = motor_control_get_duty(i);
        motor_control_set_duty(i, held);
      }
    }
  }

  /* 5. Motors: ramp toward targets */
  motor_control_update();

  /* 6. Telemetry: periodic snapshot */
  if (now - telemetry_timer >= TELEMETRY_INTERVAL_MS) {
    telemetry_timer = now;
    int bus_mA = safety_read_current_mA();
    for (int i = 0; i < FINGER_COUNT; i++) {
      logging_telemetry(i, motor_control_get_duty(i),
                        sensors_read_fsr(i), bus_mA);
    }
  }

  /* 7. Serial commands: process incoming */
  serial_cmd_update();
}
