# Parts Compatibility

## Voltage & Logic

| Component | Requirement |
|-----------|-------------|
| ESP32 | 3.3 V logic, ADC ref 3.3 V |
| Motor drivers | Logic 2.7–5.5 V; motor 4.5–12 V |
| FSR | 3.3 V + divider → ADC |
| Motors | Same battery as driver; within driver spec |

One battery for motors; common GND. ESP32 via USB or 3.3 V regulator.

## Motor Driver ↔ ESP32 ↔ Motors

- **PWM:** 1 kHz, 8-bit (config.h). Pinout: [hardware/wiring/pinout.md](../hardware/wiring/pinout.md)
- **Driver:** TB6612 = 2 motors/chip; need 3 chips for 5 motors, or 5× single-channel
- **Current:** Driver ≥ motor stall. TB6612 ~1.2 A/ch
- **Direction:** Add IN1/IN2 GPIOs if needed; pinout doc has notes

## FSR ↔ ESP32

- **FSR:** Variable R; voltage divider: 3.3 V → FSR → ADC; FSR → 10 kΩ → GND
- **ADC:** 0–3.3 V, 12-bit (ESP32); grip-stop threshold 2048 in config.h
- **Wiring:** Short runs; away from motor wires

## Mechanical

- **Filament:** PLA or PETG (PETG for joints)
- **Fasteners:** M2/M3; match CAD hole sizes

## Example Stack

| Role | Part |
|------|------|
| MCU | ESP32-WROOM-32 |
| Driver | TB6612FNG (2 ch) |
| Motor | 6 V DC gear, &lt; 1 A stall |
| FSR | Interlink FSR-402 |
| Power | 7.4 V 2S LiPo + fuse |
