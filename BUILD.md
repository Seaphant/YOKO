# YOKO — Build Process & Materials

Step-by-step build order and a **single verified parts stack** so everything works together. Use this for a reproducible, university-student-style build (e.g. internship portfolio).

---

## 1. Parts list (BOM)

Use the items in [docs/bom_template.csv](docs/bom_template.csv). For a **verified compatible stack**, see [docs/parts_compatibility.md](docs/parts_compatibility.md). Summary:

| Item | Qty | Notes |
|------|-----|--------|
| ESP32 dev board | 1 | Main MCU; 3.3 V logic |
| DC gear motor | 5 | 6 V or 12 V; &lt; ~1.2 A per motor if using TB6612 |
| Motor driver | 3–5 | e.g. TB6612 (2 motors per chip) or 5× single-channel; PWM input, logic 2.7–5.5 V |
| FSR | 5 | e.g. Interlink FSR-402; use with 10 kΩ divider to 3.3 V → ADC |
| Wire | — | 22–24 AWG for signal; heavier for motor power |
| Battery | 1 | 6–12 V per driver spec; fuse recommended |
| Fasteners | — | M2/M3 for small hand |
| 3D filament | ~500 g–1 kg | PLA or PETG (PETG preferred for joints) |

---

## 2. Build order

1. **Order parts** — Use BOM + parts_compatibility.md; keep motor voltage and driver current matched.
2. **Print parts** — [hardware/stl/README.md](hardware/stl/README.md): 0.2 mm layer, 20% infill (30–40% for joints/mounts), PLA/PETG.
3. **Assemble mechanical** — Palm, fingers, joints, motor mounts; check [artifacts/notes/mechanical_tolerances.md](artifacts/notes/mechanical_tolerances.md).
4. **Wiring** — [hardware/wiring/pinout.md](hardware/wiring/pinout.md) and [docs/wiring_notes.md](docs/wiring_notes.md): power path Battery → Fuse → Drivers → Motors; common GND; PWM and FSR pins to ESP32.
5. **Firmware** — [firmware/docs/build.md](firmware/docs/build.md): set pins in `firmware/include/config.h`, build with PlatformIO/ESP-IDF/Arduino, flash and open serial at 115200.
6. **Test** — [artifacts/tests/smoke_test_checklist.md](artifacts/tests/smoke_test_checklist.md); then current draw, homing, stall cutoff, grasp trials per [docs/testing_validation.md](docs/testing_validation.md).

---

## 3. Why this order is efficient

- **Parts first** avoids rework: compatible MCU + drivers + motors + FSR + power in one go.
- **Print then mechanical** lets you tune tolerances before committing wiring.
- **Wiring after mechanical** keeps cable lengths and strain relief correct.
- **Firmware last** (after pinout is fixed) avoids config churn.
- **Test procedures** in `/artifacts/tests` and `/logs` give a clear checklist and paper trail for portfolios.

---

## 4. Cross-references

| Step | Doc |
|------|-----|
| BOM & compatibility | [docs/bom_template.csv](docs/bom_template.csv), [docs/parts_compatibility.md](docs/parts_compatibility.md) |
| Print | [hardware/stl/README.md](hardware/stl/README.md) |
| Wiring | [hardware/wiring/](hardware/wiring/), [docs/wiring_notes.md](docs/wiring_notes.md) |
| Firmware | [firmware/README.md](firmware/README.md), [firmware/docs/build.md](firmware/docs/build.md) |
| Tests | [docs/testing_validation.md](docs/testing_validation.md), [artifacts/tests/](artifacts/tests/) |
