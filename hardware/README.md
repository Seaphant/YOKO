# YOKO — Hardware

Mechanical and electrical hardware: CAD, STL (3D-print), and wiring. 3D-printed five-finger hand with swappable parts; ESP32, motor drivers, motors, FSR.

---

## Overview

- **Mechanical:** CAD-designed; 3D-printed; 5 fingers, multi-joint, modular swappable parts. Iterations on tolerances and joints to reduce binding and backlash.
- **Electrical:** ESP32, DC gear motors ×5, motor drivers (PWM), FSR ×5 at fingertips. Power path: battery → fuse [recommended] → drivers → motors. See `docs/wiring_notes.md` and `wiring/`.

---

## Directory Layout

| Path | Contents |
|------|----------|
| `cad/` | CAD workflow, file naming, export to STL (proprietary CAD files optional in repo) |
| `stl/` | STL list, print settings (see stl/README.md), orientation and support notes |
| `wiring/` | Pinout, connectors, wiring checklist, diagram references |

---

## Cross-Reference

- **BOM:** `../docs/bom_template.csv`
- **Wiring notes:** `../docs/wiring_notes.md`
- **Diagrams:** `../artifacts/diagrams/` (system block, power, finger linkage)
- **Tests:** `../artifacts/tests/` (smoke, current draw, stall)
