/**
 * YOKO — Logging module
 * Structured serial output for debug, state transitions, and test correlation.
 * Format: [YOKO] TAG payload
 */

#ifndef LOGGING_H
#define LOGGING_H

void logging_banner(void);

void logging_test_start(const char* test_id);
void logging_test_end(const char* test_id);

void logging_state(const char* state);

/* Printf-style debug output */
void logging_debug(const char* fmt, ...);

/* Log sensor/actuator snapshot: channel, duty, FSR, current */
void logging_telemetry(int channel, int duty, int fsr, int current_mA);

#endif /* LOGGING_H */
