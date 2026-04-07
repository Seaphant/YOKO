/**
 * YOKO — Motor control module
 * PWM via ESP32 LEDC peripheral; per-finger channels with slew-rate limiting.
 */

#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H

#include "config.h"

void motor_control_init(void);

/* Set target duty for one finger. channel: 0..FINGER_COUNT-1, duty: 0..PWM_MAX_DUTY */
void motor_control_set_duty(int channel, int duty);

int motor_control_get_duty(int channel);

/* Ramp current duty toward target with rate limiting. Call every loop tick. */
void motor_control_update(void);

/* Immediate stop: all channels to zero, bypassing ramp */
void motor_control_stop_all(void);

#endif /* MOTOR_CONTROL_H */
