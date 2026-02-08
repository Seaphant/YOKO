/**
 * YOKO — Calibration / homing module
 * Homing routine, travel limits, optional nonvolatile save [TBD].
 * See docs/architecture.md (calibration).
 */

#ifndef CALIBRATION_H
#define CALIBRATION_H

#include "config.h"

/* Homing state for state machine (see artifacts/diagrams/homing_state_machine.md) */
typedef enum {
  CAL_IDLE,
  CAL_HOMING_REQUEST,
  CAL_MOVING_TO_LIMIT,
  CAL_AT_LIMIT,
  CAL_HOMING_COMPLETE,
  CAL_FAULT
} calibration_state_t;

/* Initialize; load limits from NVS if [TBD] */
void calibration_init(void);

/* Start homing sequence */
void calibration_start_homing(void);

/* Run one tick of homing state machine; call from main loop */
void calibration_update(void);

/* True when homing complete and limits valid */
int calibration_is_ready(void);

/* Get current state for serial/logging */
calibration_state_t calibration_get_state(void);

#endif /* CALIBRATION_H */
