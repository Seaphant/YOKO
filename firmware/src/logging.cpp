/**
 * YOKO — Logging implementation (stub)
 * Serial banner and test markers for /logs correlation.
 * Replace with actual Serial print [TBD] (e.g. Serial.println on ESP32).
 */

#include "logging.h"
#include "config.h"

void logging_banner(void) {
  /* [TBD] Serial.begin(SERIAL_BAUD); Serial.println("YOKO v0.1 ..."); */
  (void)SERIAL_BAUD;
}

void logging_test_start(const char* test_id) {
  (void)test_id;
  /* [TBD] Serial.println("TEST_START "); Serial.println(test_id); */
}

void logging_test_end(const char* test_id) {
  (void)test_id;
  /* [TBD] Serial.println("TEST_END "); Serial.println(test_id); */
}

void logging_state(const char* state) {
  (void)state;
  /* [TBD] Serial.print("STATE "); Serial.println(state); */
}

void logging_debug(const char* msg) {
  (void)msg;
  /* [TBD] Serial.println(msg); */
}
