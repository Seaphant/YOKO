/**
 * YOKO — Calibration / homing implementation (stub)
 * State machine: Idle -> HomingRequest -> MovingToLimit -> AtLimit -> HomingComplete.
 * Fault on over-current during homing. See artifacts/diagrams/homing_state_machine.md.
 * NVS save [TBD].
 */

#include "calibration.h"
#include "motor_control.h"
#include "safety.h"
#include "logging.h"

static calibration_state_t state = CAL_IDLE;
static int current_finger;
/* Limits per finger [TBD] */

void calibration_init(void) {
  state = CAL_IDLE;
  /* [TBD] Load limits from NVS if present */
}

void calibration_start_homing(void) {
  state = CAL_HOMING_REQUEST;
  logging_state("homing_start");
}

void calibration_update(void) {
  if (state == CAL_IDLE || state == CAL_HOMING_COMPLETE) return;
  if (safety_in_fault()) {
    state = CAL_FAULT;
    logging_state("cal_fault");
    return;
  }

  switch (state) {
    case CAL_HOMING_REQUEST:
      current_finger = 0;
      state = CAL_MOVING_TO_LIMIT;
      /* [TBD] Set motor direction toward limit */
      break;
    case CAL_MOVING_TO_LIMIT:
      /* [TBD] Check limit switch or current spike; transition to CAL_AT_LIMIT */
      /* Placeholder: assume limit reached after fixed time or sensor */
      state = CAL_AT_LIMIT;
      break;
    case CAL_AT_LIMIT:
      current_finger++;
      if (current_finger >= FINGER_COUNT) {
        state = CAL_HOMING_COMPLETE;
        logging_state("homing_complete");
        /* [TBD] Save limits to NVS */
      } else {
        state = CAL_MOVING_TO_LIMIT;
      }
      break;
    case CAL_FAULT:
      /* [TBD] Clear fault and retry or stay idle */
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
