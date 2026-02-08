/**
 * YOKO — Main loop
 * Setup: init modules, print banner, start homing.
 * Loop: calibration update, safety check, motor update, sensors, logging.
 * Toolchain: [TBD — PlatformIO / ESP-IDF / Arduino IDE]
 */

#include "config.h"
#include "motor_control.h"
#include "calibration.h"
#include "safety.h"
#include "sensors.h"
#include "logging.h"

/* [TBD] Replace with actual framework setup (Arduino setup(), ESP-IDF app_main(), etc.) */
void setup(void) {
  /* Serial for debug and test markers */
  /* Serial.begin(SERIAL_BAUD); [TBD] */

  logging_banner();

  motor_control_init();
  calibration_init();
  safety_init();
  sensors_init();

  /* Start homing on boot [TBD] or wait for command */
  calibration_start_homing();
}

void loop(void) {
  /* Safety first: check current; disable drive if over threshold (~1.5 A [PROVISIONAL]) */
  safety_update();
  if (safety_in_fault()) {
    motor_control_stop_all();
    /* Clear fault path [TBD] */
    /* continue; */
  }

  /* Calibration / homing state machine */
  calibration_update();
  if (!calibration_is_ready()) {
    motor_control_update();
    /* delay or yield [TBD] */
    return;
  }

  /* FSR grip stop: stop closing if contact threshold reached */
  sensors_update();
  if (sensors_grip_stop_triggered()) {
    /* Stop or hold [TBD] */
  }

  /* Normal operation: apply target duties with rate limiting */
  motor_control_update();

  /* [TBD] delay or yield */
}
