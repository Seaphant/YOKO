# YOKO — Firmware

ESP32 firmware for the YOKO robotic hand: PWM motor control, stall-based homing, overcurrent protection, and FSR grip-stop.

---

## Quick Start

```bash
cd firmware
pio run -e esp32          # compile
pio run -e esp32 -t upload  # flash
pio device monitor        # serial output at 115200 baud
```

Requires [PlatformIO CLI](https://docs.platformio.org/en/latest/core/installation.html) or the PlatformIO IDE extension.

---

## Overview

- **Target:** ESP32-WROOM-32 (Arduino framework)
- **Build system:** PlatformIO (`platformio.ini`)
- **Loop rate:** 100 Hz (10 ms tick)

---

## Directory Layout

| Path | Contents |
|------|----------|
| `src/` | Main loop and module source |
| `include/` | Headers and config (pinout, thresholds, calibration) |
| `docs/` | Build instructions, serial protocol, module overview |
| `platformio.ini` | Build configuration |

---

## Modules

| Module | Role |
|--------|------|
| **motor_control** | ESP32 LEDC PWM, per-finger channels, slew-rate limiting |
| **calibration** | Sequential stall-based homing, NVS persistence |
| **safety** | Shunt + INA180 current sense, debounced overcurrent cutoff |
| **sensors** | FSR ADC reads, EMA filtering, grip-stop detection |
| **logging** | Structured serial output (`[YOKO]` prefix), telemetry |

---

## Cross-Reference

- **Architecture:** `../docs/architecture.md`
- **Diagrams:** `../artifacts/diagrams/` (homing, grip-stop, PWM)
- **Test data:** `../logs/002_baseline_current_draw.md`
- **Pinout:** `../hardware/wiring/pinout.md`
