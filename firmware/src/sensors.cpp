/**
 * YOKO — Sensors implementation (stub)
 * FSR read; grip-stop threshold. Replace with actual ADC/pins [TBD].
 */

#include "sensors.h"

/* FSR threshold for grip stop [TBD] */
static const int GRIP_STOP_THRESHOLD = 512; /* Example raw ADC; replace [TBD] */
static int fsr_value[FINGER_COUNT];

void sensors_init(void) {
  for (int i = 0; i < FINGER_COUNT; i++) fsr_value[i] = 0;
  /* [TBD] Init ADC channels for FSR */
}

int sensors_read_fsr(int channel) {
  if (channel < 0 || channel >= FINGER_COUNT) return 0;
  return fsr_value[channel];
}

void sensors_update(void) {
  /* [TBD] Read FSR ADC for each finger */
  for (int i = 0; i < FINGER_COUNT; i++) {
    /* fsr_value[i] = analogRead(FSR_PIN[i]); [TBD] */
  }
}

int sensors_grip_stop_triggered(void) {
  for (int i = 0; i < FINGER_COUNT; i++) {
    if (fsr_value[i] >= GRIP_STOP_THRESHOLD) return 1;
  }
  return 0;
}
