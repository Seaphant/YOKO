# YOKO — Wiring Checklist

Pre-assembly and continuity checks before power-on. Use with `../../artifacts/tests/smoke_test_checklist.md`.

---

## Pre-Assembly

- [ ] **BOM:** All parts present (ESP32, drivers, motors, FSR, wiring, battery, fuse [recommended]); see `../../docs/bom_template.csv`.
- [ ] **Pinout:** Pinout table in `pinout.md` matches your wiring and firmware `config.h`.
- [ ] **Connectors:** Correct gender and pinout at hand base and driver/ESP32 side.
- [ ] **Strain relief:** Cable exit and flex points secured; no bare conductors at joints.

---

## Continuity (power off)

- [ ] **Battery + to fuse:** Continuity; fuse rating per driver/motor spec and correct.
- [ ] **Fuse to driver VIN:** Continuity for each driver.
- [ ] **Battery - to GND:** Common GND from battery to ESP32 and all drivers; no open circuit.
- [ ] **PWM lines:** ESP32 GPIO to driver input (no short to VIN or GND).
- [ ] **FSR:** FSR signal and reference to ESP32 ADC (see pinout.md); no short to power.

---

## Polarity and Isolation

- [ ] **Motor polarity:** Per-motor wiring consistent with firmware direction (open/close).
- [ ] **No short:** VIN to GND; signal to power. Measure with DMM before first power-on.
- [ ] **Moving parts:** Cables clear of pinch points; disconnect power before mechanical work.

---

## Post-Assembly

- [ ] **Serial:** USB/serial connected; baud set for smoke test.
- [ ] **Smoke test:** Run `../../artifacts/tests/smoke_test_checklist.md` (power-on, homing, cutoff).
- [ ] **Log:** Record any wiring change or issue in `/logs` (use `../../logs/test_log_template.md`).

---

## Cross-Reference

- **Pinout:** `pinout.md`
- **Wiring notes:** `../../docs/wiring_notes.md`
- **Power diagram:** `../../artifacts/diagrams/power_wiring.md`
- **Smoke test:** `../../artifacts/tests/smoke_test_checklist.md`
