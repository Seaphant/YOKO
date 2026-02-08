# YOKO — Firmware Build

Build and flash instructions. Toolchain: PlatformIO, ESP-IDF, or Arduino IDE with ESP32.

---

## Prerequisites

- **Toolchain:** PlatformIO Core, ESP-IDF, or Arduino IDE with ESP32 board support (e.g. espressif/esp32).
- **Target board:** ESP32 (e.g. ESP32-WROOM-32; exact module per your hardware).
- **USB:** Cable for serial and flash.

---

## Build Steps

### Option A: PlatformIO

```text
# From repo root or firmware/
pio run
pio run -t upload
pio device monitor   # serial at 115200
```

### Option B: ESP-IDF

```text
idf.py set-target esp32
idf.py build
idf.py -p /dev/cu.usbserial-* flash monitor
```

### Option C: Arduino IDE

Open `firmware/src/main.cpp` (or merge into a single .ino); select board "ESP32 Dev Module"; set port; Build and Upload.

---

## Configuration

- **Pinout:** Edit `include/config.h` or add pin defines; PWM and FSR pins in `hardware/wiring/pinout.md`.
- **Thresholds:** `SAFETY_CURRENT_THRESHOLD_MA` — replace [PROVISIONAL] 1500 with verified value (see `/logs`).
- **Serial baud:** 115200 in config.h (SERIAL_BAUD).

---

## Output

- **Binary:** e.g. `.pio/build/esp32dev/firmware.bin` (PlatformIO) or `build/*.bin` (ESP-IDF).
- **Flash:** Default partition table; adjust if using OTA or custom layout.

---

## Cross-Reference

- **Architecture:** `../../docs/architecture.md`
- **Serial protocol:** `serial_protocol.md`
- **Modules:** `modules.md`
