/**
 * YOKO — Motor control
 * ESP32 LEDC PWM with per-channel slew-rate limiting to reduce
 * mechanical shock and inrush current on direction changes.
 */

#include "motor_control.h"

static int current_duty[FINGER_COUNT];
static int target_duty[FINGER_COUNT];

void motor_control_init(void) {
  for (int i = 0; i < FINGER_COUNT; i++) {
    ledcSetup(LEDC_CHANNELS[i], PWM_FREQ_HZ, PWM_RESOLUTION_BITS);
    ledcAttachPin(PWM_PINS[i], LEDC_CHANNELS[i]);
    ledcWrite(LEDC_CHANNELS[i], 0);
    current_duty[i] = 0;
    target_duty[i] = 0;
  }
}

void motor_control_set_duty(int channel, int duty) {
  if (channel < 0 || channel >= FINGER_COUNT) return;
  if (duty < 0) duty = 0;
  if (duty > PWM_MAX_DUTY) duty = PWM_MAX_DUTY;
  target_duty[channel] = duty;
}

int motor_control_get_duty(int channel) {
  if (channel < 0 || channel >= FINGER_COUNT) return 0;
  return current_duty[channel];
}

void motor_control_update(void) {
  for (int i = 0; i < FINGER_COUNT; i++) {
    int diff = target_duty[i] - current_duty[i];

    if (diff > PWM_RATE_LIMIT_DELTA)
      current_duty[i] += PWM_RATE_LIMIT_DELTA;
    else if (diff < -PWM_RATE_LIMIT_DELTA)
      current_duty[i] -= PWM_RATE_LIMIT_DELTA;
    else
      current_duty[i] = target_duty[i];

    ledcWrite(LEDC_CHANNELS[i], current_duty[i]);
  }
}

void motor_control_stop_all(void) {
  for (int i = 0; i < FINGER_COUNT; i++) {
    target_duty[i] = 0;
    current_duty[i] = 0;
    ledcWrite(LEDC_CHANNELS[i], 0);
  }
}
