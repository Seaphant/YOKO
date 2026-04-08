/**
 * YOKO — Safety / over-current protection
 * Reads bus current via shunt resistor + INA180 amplifier on ADC1.
 * Debounces the threshold to avoid false trips from motor inrush,
 * then latches a fault and kills all PWM outputs.
 */

#include "safety.h"
#include "motor_control.h"
#include "logging.h"

static volatile int fault_flag;
static volatile int debounce_counter;

void safety_init(void) {
  fault_flag = 0;
  debounce_counter = 0;
  pinMode(CURRENT_SENSE_PIN, INPUT);
  analogReadResolution(12);
}

int safety_read_current_mA(void) {
  int counts = analogRead(CURRENT_SENSE_PIN);
  /* Convert ADC counts -> millivolts -> milliamps using shunt calibration */
  long mv = ((long)counts * ADC_REF_MV) / ADC_MAX_COUNTS;
  int mA = (int)((mv * 1000L) / CURRENT_SENSE_MV_PER_A);
  return mA;
}

void safety_update(void) {
  if (fault_flag) return;

  int current = safety_read_current_mA();

  if (current >= SAFETY_CURRENT_THRESHOLD_MA) {
    debounce_counter++;
    if (debounce_counter >= SAFETY_DEBOUNCE_COUNT) {
      fault_flag = 1;
      motor_control_stop_all();
      logging_debug("FAULT: %d mA exceeded %d mA threshold",
                    current, SAFETY_CURRENT_THRESHOLD_MA);
      logging_state("safety_cutoff");
    }
  } else {
    debounce_counter = 0;
  }
}

int safety_in_fault(void) {
  return fault_flag;
}

void safety_clear_fault(void) {
  int current = safety_read_current_mA();
  if (current >= SAFETY_CURRENT_THRESHOLD_MA) {
    logging_debug("Cannot clear fault: current still %d mA", current);
    return;
  }
  fault_flag = 0;
  debounce_counter = 0;
  logging_state("safety_clear");
}
