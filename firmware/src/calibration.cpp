/**
 * YOKO — Calibration / homing
 * Homes each finger sequentially by driving toward the mechanical stop
 * at low duty and detecting stall via current rise. Records the position
 * as travel limit, backs off, then advances to the next finger.
 * Limits persist across reboots via ESP32 NVS.
 */

#include "calibration.h"
#include "motor_control.h"
#include "safety.h"
#include "logging.h"
#include <Preferences.h>

static calibration_state_t state;
static int current_finger;
static unsigned long state_enter_ms;
static int limits[FINGER_COUNT];

static Preferences prefs;

static void enter_state(calibration_state_t next) {
  state = next;
  state_enter_ms = millis();
}

void calibration_init(void) {
  state = CAL_IDLE;
  current_finger = 0;

  prefs.begin(NVS_NAMESPACE, true);
  bool loaded = prefs.isKey(NVS_KEY_LIMITS);
  if (loaded) {
    prefs.getBytes(NVS_KEY_LIMITS, limits, sizeof(limits));
    logging_debug("NVS: loaded limits for %d fingers", FINGER_COUNT);
  } else {
    for (int i = 0; i < FINGER_COUNT; i++) limits[i] = PWM_MAX_DUTY;
    logging_debug("NVS: no saved limits, using defaults");
  }
  prefs.end();
}

static void save_limits(void) {
  prefs.begin(NVS_NAMESPACE, false);
  prefs.putBytes(NVS_KEY_LIMITS, limits, sizeof(limits));
  prefs.end();
  logging_debug("NVS: saved limits");
}

void calibration_start_homing(void) {
  current_finger = 0;
  enter_state(CAL_HOMING_REQUEST);
  logging_state("homing_start");
}

void calibration_update(void) {
  if (state == CAL_IDLE || state == CAL_HOMING_COMPLETE) return;

  if (safety_in_fault()) {
    motor_control_stop_all();
    enter_state(CAL_FAULT);
    logging_state("cal_fault");
    return;
  }

  unsigned long elapsed = millis() - state_enter_ms;

  switch (state) {

    case CAL_HOMING_REQUEST:
      logging_debug("Homing finger %d", current_finger);
      motor_control_set_duty(current_finger, HOMING_DUTY);
      enter_state(CAL_MOVING_TO_LIMIT);
      break;

    case CAL_MOVING_TO_LIMIT: {
      int current_mA = safety_read_current_mA();

      if (current_mA >= HOMING_STALL_MA) {
        /* Stall detected — finger reached its mechanical stop */
        limits[current_finger] = motor_control_get_duty(current_finger);
        motor_control_set_duty(current_finger, 0);
        logging_debug("Finger %d limit at duty %d (stall %d mA)",
                      current_finger, limits[current_finger], current_mA);
        enter_state(CAL_AT_LIMIT);
        break;
      }

      if (elapsed > HOMING_TIMEOUT_MS) {
        /* Timed out without stall — accept current position as limit */
        motor_control_set_duty(current_finger, 0);
        limits[current_finger] = PWM_MAX_DUTY;
        logging_debug("Finger %d homing timeout, using max limit", current_finger);
        enter_state(CAL_AT_LIMIT);
        break;
      }
      break;
    }

    case CAL_AT_LIMIT:
      /* Brief backoff to release mechanical preload */
      motor_control_set_duty(current_finger, HOMING_BACKOFF_DUTY);

      if (elapsed >= HOMING_BACKOFF_MS) {
        motor_control_set_duty(current_finger, 0);
        current_finger++;

        if (current_finger >= FINGER_COUNT) {
          save_limits();
          enter_state(CAL_HOMING_COMPLETE);
          logging_state("homing_complete");
        } else {
          enter_state(CAL_HOMING_REQUEST);
        }
      }
      break;

    case CAL_FAULT:
      /* Remain faulted until safety clears and homing is restarted */
      break;

    default:
      break;
  }
}

int calibration_is_ready(void) {
  return state == CAL_HOMING_COMPLETE;
}

calibration_state_t calibration_get_state(void) {
  return state;
}

int calibration_get_limit(int channel) {
  if (channel < 0 || channel >= FINGER_COUNT) return 0;
  return limits[channel];
}
