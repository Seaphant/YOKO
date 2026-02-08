/**
 * YOKO — Sensors module
 * FSR fingertips for closed-loop grip stop. Optional expansion [TBD].
 * See docs/architecture.md (sensors).
 */

#ifndef SENSORS_H
#define SENSORS_H

#include "config.h"

/* Initialize FSR ADC/pins */
void sensors_init(void);

/* Read FSR value(s). Return raw or scaled [TBD]. Per-finger or combined. */
int sensors_read_fsr(int channel);

/* True if any FSR above grip-stop threshold (closed-loop stop) */
int sensors_grip_stop_triggered(void);

/* Update readings; call from main loop */
void sensors_update(void);

#endif /* SENSORS_H */
