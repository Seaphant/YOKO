/**
 * YOKO — Structured serial logging
 * All output prefixed with [YOKO] for easy filtering in serial monitors
 * and automated log capture scripts.
 */

#include "logging.h"
#include "config.h"
#include <Arduino.h>
#include <stdarg.h>

static char fmt_buf[128];

void logging_banner(void) {
  Serial.begin(SERIAL_BAUD);
  while (!Serial && millis() < 2000) { /* wait up to 2 s for USB CDC */ }
  Serial.println();
  Serial.println(F("[YOKO] ============================"));
  Serial.println(F("[YOKO]  YOKO Robotic Hand v0.2"));
  Serial.println(F("[YOKO]  ESP32 / 5-finger PWM+FSR"));
  Serial.println(F("[YOKO] ============================"));
  Serial.print(F("[YOKO] Loop interval: "));
  Serial.print(LOOP_INTERVAL_MS);
  Serial.println(F(" ms"));
}

void logging_test_start(const char* test_id) {
  Serial.print(F("[YOKO] TEST_START "));
  Serial.println(test_id);
}

void logging_test_end(const char* test_id) {
  Serial.print(F("[YOKO] TEST_END "));
  Serial.println(test_id);
}

void logging_state(const char* state) {
  Serial.print(F("[YOKO] STATE "));
  Serial.println(state);
}

void logging_debug(const char* fmt, ...) {
  va_list args;
  va_start(args, fmt);
  vsnprintf(fmt_buf, sizeof(fmt_buf), fmt, args);
  va_end(args);
  Serial.print(F("[YOKO] "));
  Serial.println(fmt_buf);
}

void logging_telemetry(int channel, int duty, int fsr, int current_mA) {
  snprintf(fmt_buf, sizeof(fmt_buf), "CH%d duty=%d fsr=%d mA=%d",
           channel, duty, fsr, current_mA);
  Serial.print(F("[YOKO] TEL "));
  Serial.println(fmt_buf);
}
