/**
 * YOKO — Safety implementation (stub)
 * Over-current detection; stall cutoff ~1.5 A [PROVISIONAL].
 * Replace with actual current sense (e.g. shunt + ADC, or driver fault pin) [TBD].
 */

#include "safety.h"
#include "motor_control.h"
#include "logging.h"

static int fault_flag = 0;
/* [TBD] ADC channel or driver fault pin for current sense */

void safety_init(void) {
  fault_flag = 0;
  /* [TBD] Init ADC or fault input */
}

int safety_read_current_mA(void) {
  /* [TBD] Read shunt/ADC; return mA */
  return 0;
}

void safety_update(void) {
  int current = safety_read_current_mA();
  if (current >= SAFETY_CURRENT_THRESHOLD_MA) {
    fault_flag = 1;
    motor_control_stop_all();
    logging_state("safety_cutoff");
  }
}

int safety_in_fault(void) {
  return fault_flag;
}

void safety_clear_fault(void) {
  fault_flag = 0;
  logging_state("safety_clear");
  /* [TBD] Re-enable drive after release */
}
