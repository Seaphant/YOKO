/**
 * YOKO — Safety module
 * Over-current detection with debounced stall cutoff.
 * Uses shunt resistor + amplifier on CURRENT_SENSE_PIN (ADC1).
 */

#ifndef SAFETY_H
#define SAFETY_H

#include "config.h"

void safety_init(void);

/* Read instantaneous bus current in milliamps */
int safety_read_current_mA(void);

/* Check threshold with debounce; latch fault and kill motors if triggered */
void safety_update(void);

int safety_in_fault(void);

/* Clear latched fault after the overcurrent condition is resolved */
void safety_clear_fault(void);

#endif /* SAFETY_H */
