/**
 * YOKO — Serial command handler
 * Parses line-oriented commands from the USB serial port.
 *
 * Supported commands:
 *   help         — list available commands
 *   status       — print mode, fault state, finger duties, bus current
 *   open <duty>  — set all fingers to target duty (0-255)
 *   close        — set all fingers to zero
 *   home         — restart homing sequence
 *   clear        — clear latched safety fault (if current is safe)
 */

#include "serial_cmd.h"
#include <Arduino.h>
#include <string.h>
#include "config.h"
#include "motor_control.h"
#include "calibration.h"
#include "safety.h"
#include "sensors.h"
#include "logging.h"

static char line_buf[64];
static uint8_t line_len;

static void handle_line(const char *line) {
  while (*line == ' ') line++;

  if (strlen(line) == 0) return;

  if (strcmp(line, "help") == 0) {
    Serial.println(F("[YOKO] CMD commands: help | status | open <duty> | close | home | clear"));
    return;
  }

  if (strcmp(line, "status") == 0) {
    const char *mode = calibration_is_ready() ? "RUN" : "HOMING";
    if (safety_in_fault()) mode = "FAULT";

    Serial.print(F("[YOKO] CMD status mode="));
    Serial.print(mode);
    Serial.print(F(" current_mA="));
    Serial.print(safety_read_current_mA());
    for (int i = 0; i < FINGER_COUNT; i++) {
      Serial.print(F(" ch"));
      Serial.print(i);
      Serial.print(F("="));
      Serial.print(motor_control_get_duty(i));
      Serial.print(F("/"));
      Serial.print(calibration_get_limit(i));
    }
    Serial.println();
    return;
  }

  if (strncmp(line, "open", 4) == 0) {
    int duty = PWM_MAX_DUTY;
    if (line[4] == ' ') {
      duty = atoi(line + 5);
      if (duty < 0) duty = 0;
      if (duty > PWM_MAX_DUTY) duty = PWM_MAX_DUTY;
    }
    for (int i = 0; i < FINGER_COUNT; i++) {
      motor_control_set_duty(i, duty);
    }
    logging_debug("CMD open duty=%d", duty);
    return;
  }

  if (strcmp(line, "close") == 0) {
    for (int i = 0; i < FINGER_COUNT; i++) {
      motor_control_set_duty(i, 0);
    }
    logging_debug("CMD close");
    return;
  }

  if (strcmp(line, "home") == 0) {
    motor_control_stop_all();
    calibration_start_homing();
    logging_debug("CMD home");
    return;
  }

  if (strcmp(line, "clear") == 0) {
    safety_clear_fault();
    return;
  }

  Serial.print(F("[YOKO] CMD ERR unknown: "));
  Serial.println(line);
}

void serial_cmd_init(void) {
  line_len = 0;
  line_buf[0] = '\0';
}

void serial_cmd_update(void) {
  while (Serial.available()) {
    char ch = (char)Serial.read();
    if (ch == '\r' || ch == '\n') {
      if (line_len > 0) {
        line_buf[line_len] = '\0';
        handle_line(line_buf);
        line_len = 0;
      }
      continue;
    }
    if (line_len < sizeof(line_buf) - 1) {
      line_buf[line_len++] = ch;
    }
  }
}
