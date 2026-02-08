# YOKO — Pinout

ESP32 pin assignments for motor drivers (PWM), FSR (ADC), and optional current sense. Example pins below; set per your wiring and driver/board.

---

## Motor Drivers (PWM)

| Finger | ESP32 GPIO (example) | Driver pin | Notes |
|--------|----------------------|------------|-------|
| Thumb  | 25                   | PWM IN 1   | PWM 1; 1 kHz, 8-bit (see config.h) |
| Index  | 26                   | PWM IN 2   | PWM 2 |
| Middle | 27                   | PWM IN 3   | PWM 3 |
| Ring   | 32                   | PWM IN 4   | PWM 4 |
| Pinky  | 33                   | PWM IN 5   | PWM 5 |

- **PWM frequency / resolution:** 1 kHz, 8-bit in `../../firmware/include/config.h` (PWM_FREQ_HZ, PWM_RESOLUTION_BITS).
- **Driver type:** Single PWM per channel (speed) or dual PWM (direction + speed); adjust firmware if using direction pins.

---

## FSR (ADC)

| Finger | ESP32 ADC / GPIO (example) | Notes |
|--------|---------------------------|-------|
| Thumb  | 34 (ADC1_CH6)             | FSR 1 |
| Index  | 35 (ADC1_CH7)             | FSR 2 |
| Middle | 36 (ADC1_CH0)             | FSR 3 |
| Ring   | 39 (ADC1_CH3)             | FSR 4 |
| Pinky  | 4  (ADC2_CH0)             | FSR 5 (ADC2 if WiFi not used) |

- **Grip-stop threshold:** 512 (0–1023 raw) in firmware `sensors.cpp` / config.h (FSR_GRIP_STOP_THRESHOLD).

---

## Power and Ground

| Signal    | ESP32   | Driver / FSR        |
|-----------|---------|----------------------|
| GND       | GND     | Common GND           |
| VIN (logic) | 3.3 V   | Driver logic; FSR VCC (3.3 V typical) |
| Motor VIN | —       | Battery via fuse (e.g. 5–12 V per driver spec) |

---

## Optional: Current Sense

- **Shunt + ADC:** e.g. GPIO 38 (ADC1) for shunt voltage; scale to mA in firmware.
- **Driver fault pin:** If driver has FAULT output, connect to GPIO and read in safety module.

---

## Sync with Firmware

After finalizing pins, add `#define PWM_PIN_*` and `FSR_PIN_*` in `../../firmware/include/config.h` (or in .cpp) and use in `motor_control.cpp`, `sensors.cpp`, `safety.cpp`. Document here and in wiring checklist.
