# YOKO — Wiring

Pinout, connectors, and wiring checklist. Power path: battery → fuse [recommended] → motor drivers → motors. ESP32 PWM to drivers; FSR to ESP32 ADC; common GND.

---

## Contents

| File | Description |
|------|-------------|
| **pinout.md** | ESP32 pins to drivers, FSR, power; [TBD] until finalized |
| **wiring_checklist.md** | Pre-assembly and continuity checklist |

---

## Power Path (summary)

- **Battery +** → Fuse / current limit [recommended] → Motor drivers (VIN) → Motors
- **Battery -** → Common GND → ESP32 GND, driver GND
- **Signal:** ESP32 GPIO (PWM) → Driver enable/direction [TBD]; FSR → ESP32 ADC [TBD]

Full diagram: `../../artifacts/diagrams/power_wiring.md`. Safety and measurement: `../../docs/wiring_notes.md`.

---

## Connectors and Strain Relief

- Secure connectors at hand base and at driver/ESP32 side.
- Strain relief at flex points (fingers, cable exit).
- Label or color-code channels for debugging (see `../../artifacts/tests/` for test procedures).

---

## Cross-Reference

- **Wiring notes:** `../../docs/wiring_notes.md`
- **Power diagram:** `../../artifacts/diagrams/power_wiring.md`, `system_block.md`
- **Firmware config:** `../../firmware/include/config.h` (pins [TBD])
- **BOM:** `../../docs/bom_template.csv`
