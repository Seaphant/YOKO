/**
 * YOKO — Sensors module
 * FSR fingertip pressure via ESP32 ADC with EMA filtering.
 */

#ifndef SENSORS_H
#define SENSORS_H

#include "config.h"

void sensors_init(void);

/* Get filtered FSR reading for a finger (0..FINGER_COUNT-1). Returns 0-4095. */
int sensors_read_fsr(int channel);

/* True if any finger's FSR exceeds grip-stop threshold */
int sensors_grip_stop_triggered(void);

/* Sample all FSR channels and update filtered values. Call every loop tick. */
void sensors_update(void);

#endif /* SENSORS_H */
