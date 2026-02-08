/**
 * YOKO — Safety module
 * Over-current detection, stall cutoff, optional thermal cooldown [TBD].
 * Threshold ~1.5 A [PROVISIONAL] — replace with verified value (see logs/).
 * See docs/architecture.md (safety).
 */

#ifndef SAFETY_H
#define SAFETY_H

#include "config.h"

/* Initialize current sense and cutoff */
void safety_init(void);

/* Read current (mA); channel or bus [TBD] */
int safety_read_current_mA(void);

/* Check threshold; disable drive if over. Call from main loop. */
void safety_update(void);

/* True if in fault state (cutoff triggered) */
int safety_in_fault(void);

/* Clear fault (after release); allow re-homing [TBD] */
void safety_clear_fault(void);

#endif /* SAFETY_H */
