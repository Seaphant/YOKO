/**
 * YOKO — Calibration / homing module
 * Sequential per-finger homing via stall detection with NVS persistence.
 * State machine: Idle -> HomingRequest -> MovingToLimit -> AtLimit -> HomingComplete.
 */

#ifndef CALIBRATION_H
#define CALIBRATION_H

#include "config.h"

typedef enum {
  CAL_IDLE,
  CAL_HOMING_REQUEST,
  CAL_MOVING_TO_LIMIT,
  CAL_AT_LIMIT,
  CAL_HOMING_COMPLETE,
  CAL_FAULT
} calibration_state_t;

void calibration_init(void);
void calibration_start_homing(void);

/* Run one tick of the homing state machine. Call every loop tick. */
void calibration_update(void);

int calibration_is_ready(void);
calibration_state_t calibration_get_state(void);

/* Per-finger travel limit learned during homing (duty cycles to full close) */
int calibration_get_limit(int channel);

#endif /* CALIBRATION_H */
