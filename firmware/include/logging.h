/**
 * YOKO — Logging module
 * Serial debug output and test markers for correlation with repo /logs.
 * See docs/architecture.md (logging).
 */

#ifndef LOGGING_H
#define LOGGING_H

/* Print banner on boot (version, build [TBD]) */
void logging_banner(void);

/* Print test start/end marker for /logs correlation (e.g. TEST_START smoke_001) */
void logging_test_start(const char* test_id);
void logging_test_end(const char* test_id);

/* State change: homing, fault, grip stop */
void logging_state(const char* state);

/* Optional: current, duty, FSR for debug [TBD] */
void logging_debug(const char* msg);

#endif /* LOGGING_H */
