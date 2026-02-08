# YOKO — Firmware Build

Build and flash instructions. Toolchain [TBD — PlatformIO / ESP-IDF / Arduino IDE].

---

## Prerequisites

- **Toolchain:** [TBD] — e.g. PlatformIO Core, ESP-IDF, or Arduino IDE with ESP32 board support
- **Target board:** ESP32 (exact module [TBD])
- **USB:** Cable for serial and flash

---

## Build Steps [TBD]

### Option A: PlatformIO

```text
# [TBD] Example; adjust env name and board
# pio run
# pio run -t upload
```

### Option B: ESP-IDF

```text
# [TBD] idf.py build
# idf.py -p PORT flash monitor
```

### Option C: Arduino IDE

```text
# [TBD] Open sketch; select ESP32 board; Build / Upload
```

---

## Configuration

- **Pinout:** Edit `include/config.h` (PWM pins, FSR ADC, current sense [TBD])
- **Thresholds:** `SAFETY_CURRENT_THRESHOLD_MA` — replace [PROVISIONAL] 1500 with verified value (see `/logs`)
- **Serial baud:** `SERIAL_BAUD` in config.h

---

## Output

- **Binary:** [TBD] — e.g. `.pio/build/.../firmware.bin` or `build/*.bin`
- **Flash address:** [TBD] per ESP32 partition table

---

## Cross-Reference

- **Architecture:** `../../docs/architecture.md`
- **Serial protocol:** `serial_protocol.md`
- **Modules:** `modules.md`
