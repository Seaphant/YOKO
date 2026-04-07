/**
 * YOKO — FSR sensor driver
 * Reads force-sensitive resistors on each fingertip via ESP32 ADC.
 * Applies exponential moving average (EMA) to reject noise from motor PWM
 * coupling and contact bounce.
 */

#include "sensors.h"

static int fsr_raw[FINGER_COUNT];
static int fsr_filtered[FINGER_COUNT];

void sensors_init(void) {
  analogReadResolution(12);
  analogSetAttenuation(ADC_11db);

  for (int i = 0; i < FINGER_COUNT; i++) {
    pinMode(FSR_PINS[i], INPUT);
    fsr_raw[i] = 0;
    fsr_filtered[i] = 0;
  }

  /* Prime the filter with a few initial reads */
  for (int warmup = 0; warmup < 8; warmup++) {
    for (int i = 0; i < FINGER_COUNT; i++) {
      fsr_raw[i] = analogRead(FSR_PINS[i]);
      fsr_filtered[i] = fsr_raw[i];
    }
  }
}

int sensors_read_fsr(int channel) {
  if (channel < 0 || channel >= FINGER_COUNT) return -1;
  return fsr_filtered[channel];
}

void sensors_update(void) {
  for (int i = 0; i < FINGER_COUNT; i++) {
    fsr_raw[i] = analogRead(FSR_PINS[i]);

    /* EMA: filtered = alpha/256 * filtered + (256-alpha)/256 * raw
     * Higher FSR_EMA_ALPHA = heavier smoothing */
    fsr_filtered[i] = ((long)FSR_EMA_ALPHA * fsr_filtered[i] +
                        (long)(256 - FSR_EMA_ALPHA) * fsr_raw[i]) / 256;
  }
}

int sensors_grip_stop_triggered(void) {
  for (int i = 0; i < FINGER_COUNT; i++) {
    if (fsr_filtered[i] >= FSR_GRIP_STOP_THRESHOLD) return 1;
  }
  return 0;
}
