# YOKO — Firmware

ESP32 firmware for the YOKO robotic hand: PWM motor control, calibration/homing, over-current cutoff, and FSR grip-stop.

---

## Overview

- **Target:** ESP32
- **Modules:** motor_control, calibration, safety, sensors, logging (see `docs/architecture.md` in repo root)
- **Toolchain:** [TBD — PlatformIO / ESP-IDF / Arduino IDE]; do not overclaim
- **Build:** See [firmware/docs/build.md](docs/build.md)

---

## Directory Layout

| Path | Contents |
|------|----------|
| `src/` | Main loop and module source (motor_control, calibration, safety, sensors) |
| `include/` | Headers and config (pinout, thresholds, channel count) |
| `docs/` | Build instructions, serial protocol, module overview |

---

## Module Summary

| Module | Role |
|--------|------|
| **motor_control** | PWM to drivers, per-finger channels, rate limiting |
| **calibration** | Homing routine, travel limits, nonvolatile save [TBD] |
| **safety** | Over-current detection, stall cutoff (~1.5 A [PROVISIONAL]) |
| **sensors** | FSR read, grip-stop threshold |
| **logging** | Serial debug, test markers for `/logs` |

---

## Cross-Reference

- **Architecture:** `../docs/architecture.md`
- **Diagrams:** `../artifacts/diagrams/` (homing, grip-stop, PWM)
- **Tests:** `../artifacts/tests/`, `../logs/`
