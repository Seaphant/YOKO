/**
 * YOKO — Firmware configuration
 * Pinout in hardware/wiring/pinout.md; thresholds and channel counts below.
 */

#ifndef CONFIG_H
#define CONFIG_H

/* Number of fingers / motor channels */
#define FINGER_COUNT 5

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
