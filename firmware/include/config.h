/**
 * YOKO — Firmware configuration
 * Pinout in hardware/wiring/pinout.md; thresholds and channel counts below.
 */

#ifndef CONFIG_H
#define CONFIG_H

/* Number of fingers / motor channels */
#define FINGER_COUNT 5

/* PWM output pins (Thumb, Index, Middle, Ring, Pinky) — sync hardware/wiring/pinout.md */
#define PWM_PIN_THUMB   25
#define PWM_PIN_INDEX   26
#define PWM_PIN_MIDDLE  27
#define PWM_PIN_RING    32
#define PWM_PIN_PINKY   33

/* FSR ADC pins (Thumb..Pinky) */
#define FSR_PIN_THUMB   34
#define FSR_PIN_INDEX   35
#define FSR_PIN_MIDDLE  36
#define FSR_PIN_RING    39
#define FSR_PIN_PINKY   4

/* Current sense: shunt + ADC (GPIO 38, ADC1) */
#define CURRENT_SENSE_PIN 38

/* PWM: 1 kHz, 8-bit resolution; adjust per driver spec */
#define PWM_FREQ_HZ 1000
#define PWM_RESOLUTION_BITS 8
/* Rate limit: max duty delta per cycle (smoother motion) */
#define PWM_RATE_LIMIT_DELTA 10

/* Safety: stall/over-current threshold ~1.5 A [PROVISIONAL] — replace with verified value */
#define SAFETY_CURRENT_THRESHOLD_MA 1500

/* FSR: ADC channels in sensors.cpp; grip-stop threshold 512 (0–1023 raw ADC) */
#define FSR_GRIP_STOP_THRESHOLD 512

/* Serial: 115200 baud for debug and test markers */
#define SERIAL_BAUD 115200

/* NVS namespace and key for stored homing limits */
#define NVS_NAMESPACE "yoko"
#define NVS_KEY_LIMITS "limits"

#endif /* CONFIG_H */
