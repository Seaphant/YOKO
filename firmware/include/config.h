/**
 * YOKO — Firmware configuration
 * Pinout in hardware/wiring/pinout.md; thresholds and channel counts below.
 */

#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>

#define FINGER_COUNT 5

/* PWM output pins (Thumb, Index, Middle, Ring, Pinky) — sync hardware/wiring/pinout.md */
static const uint8_t PWM_PINS[FINGER_COUNT] = {25, 26, 27, 32, 33};

/* LEDC channels mapped 1:1 with fingers */
static const uint8_t LEDC_CHANNELS[FINGER_COUNT] = {0, 1, 2, 3, 4};

/* FSR ADC input pins */
static const uint8_t FSR_PINS[FINGER_COUNT] = {34, 35, 36, 39, 4};

/* Current sense: shunt amplifier output on ADC1 */
#define CURRENT_SENSE_PIN       38

/* Shunt calibration: millivolts-per-amp for the sense resistor + amplifier stage.
 * With a 0.1 ohm shunt and 20x INA180 gain, 1 A produces 2000 mV. */
#define CURRENT_SENSE_MV_PER_A  2000

/* ADC reference for ESP32 (default attenuation, ~3.3 V full scale, 12-bit) */
#define ADC_MAX_COUNTS          4095
#define ADC_REF_MV              3300

/* PWM: 1 kHz, 8-bit resolution */
#define PWM_FREQ_HZ             1000
#define PWM_RESOLUTION_BITS     8
#define PWM_MAX_DUTY            ((1 << PWM_RESOLUTION_BITS) - 1)  // 255

/* Rate limit: max duty change per update cycle (prevents current spikes) */
#define PWM_RATE_LIMIT_DELTA    10

/* Safety: stall/over-current cutoff threshold */
#define SAFETY_CURRENT_THRESHOLD_MA   1500
/* Consecutive over-threshold samples before latching fault (debounce) */
#define SAFETY_DEBOUNCE_COUNT         5

/* FSR grip-stop threshold (12-bit raw ADC, 0-4095) */
#define FSR_GRIP_STOP_THRESHOLD 2048

/* EMA filter coefficient for FSR smoothing (0-255, higher = more smoothing) */
#define FSR_EMA_ALPHA           200

/* Homing: slow duty and stall-detection current for finding limits */
#define HOMING_DUTY             80
#define HOMING_STALL_MA         800
#define HOMING_TIMEOUT_MS       3000
#define HOMING_BACKOFF_DUTY     40
#define HOMING_BACKOFF_MS       200

/* Serial: 115200 baud for debug and test markers */
#define SERIAL_BAUD             115200

/* NVS namespace and key for persistent homing limits */
#define NVS_NAMESPACE           "yoko"
#define NVS_KEY_LIMITS          "limits"

/* Main loop tick rate */
#define LOOP_INTERVAL_MS        10

#endif /* CONFIG_H */
