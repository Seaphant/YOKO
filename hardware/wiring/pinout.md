# YOKO — Pinout

ESP32 pin assignments for motor drivers (PWM), FSR (ADC), and optional current sense. Replace [TBD] with actual pins when finalized.

---

## Motor Drivers (PWM)

| Finger | ESP32 GPIO [TBD] | Driver pin [TBD] | Notes |
|--------|------------------|------------------|------|
| Thumb  | [TBD]            | [TBD]            | PWM 1 |
| Index  | [TBD]            | [TBD]            | PWM 2 |
| Middle | [TBD]            | [TBD]            | PWM 3 |
| Ring   | [TBD]            | [TBD]            | PWM 4 |
| Pinky  | [TBD]            | [TBD]            | PWM 5 |

- **PWM frequency / resolution:** [TBD]; set in `../../firmware/include/config.h`.
- **Driver type:** [TBD] — direction vs single PWM per channel; adjust firmware if needed.

---

## FSR (ADC)

| Finger | ESP32 ADC / GPIO [TBD] | Notes |
|--------|------------------------|------|
| Thumb  | [TBD]                  | FSR 1 |
| Index  | [TBD]                  | FSR 2 |
| Middle | [TBD]                  | FSR 3 |
| Ring   | [TBD]                  | FSR 4 |
| Pinky  | [TBD]                  | FSR 5 |

- **Grip-stop threshold:** [TBD] in firmware `sensors.cpp` / config.

---

## Power and Ground

| Signal | ESP32 | Driver / FSR |
|--------|-------|---------------|
| GND    | GND   | Common GND    |
| VIN (logic) | [TBD] 3.3 V or 5 V | Driver logic, FSR [TBD] |
| Motor VIN   | —     | Battery via fuse [TBD] |

---

## Optional: Current Sense

- **Shunt + ADC:** [TBD] pin and channel for current sense (safety cutoff).
- **Driver fault pin:** [TBD] if driver has fault output.

---

## Sync with Firmware

After finalizing pins, update `../../firmware/include/config.h` and any pin #defines in `motor_control.cpp`, `sensors.cpp`, `safety.cpp`. Document here and in wiring checklist.
