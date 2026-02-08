/**
 * YOKO — Firmware configuration
 * Pinout, thresholds, and channel counts. Replace [TBD] with actual values.
 */

#ifndef CONFIG_H
#define CONFIG_H

/* Number of fingers / motor channels */
#define FINGER_COUNT 5

/* PWM: frequency [TBD] Hz, resolution [TBD] bits */
/* Rate limit: max duty delta per cycle [TBD] */

/* Safety: stall/over-current threshold ~1.5 A [PROVISIONAL] — replace with verified value */
#define SAFETY_CURRENT_THRESHOLD_MA 1500

/* FSR: ADC channel or pin [TBD]; grip-stop threshold [TBD] */

/* Serial: baud rate [TBD] */
#define SERIAL_BAUD 115200

/* Optional: NVS keys for stored limits [TBD] */

#endif /* CONFIG_H */
