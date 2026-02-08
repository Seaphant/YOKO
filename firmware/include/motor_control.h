/**
 * YOKO — Motor control module
 * PWM interfaces to motor drivers; per-finger channels; rate limiting.
 * See docs/architecture.md (motor_control).
 */

#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H

#include "config.h"

/* Initialize PWM pins and driver state */
void motor_control_init(void);

/* Set target duty for one finger. Channel 0..FINGER_COUNT-1; duty in range [TBD] */
void motor_control_set_duty(int channel, int duty);

/* Update outputs with rate limiting (call from main loop) */
void motor_control_update(void);

/* Emergency stop: all channels to neutral/off */
void motor_control_stop_all(void);

#endif /* MOTOR_CONTROL_H */
