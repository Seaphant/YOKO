# YOKO — 3D-Printed Robotic Hand

Five-finger robotic hand with 3D-printed mechanicals, ESP32 control, and closed-loop grip sensing. Modular design for iterative development.

## Overview

| Domain | Implementation |
|--------|----------------|
| **Mechanical** | 5 fingers × 3 phalanxes; pin joints; swappable parts; PLA/PETG |
| **Electrical** | ESP32, TB6612/DRV8833 drivers, 6–12 V DC gear motors, FSR fingertips |
| **Firmware** | PWM per finger, homing/calibration, stall cutoff, FSR grip-stop |

```
[Battery] → [Fuse] → [Motor Drivers] → [Motors ×5]
     ↑                    ↑
[ESP32] ←── PWM ──────────┘
     ↑
[FSR Fingertips] → grip-stop feedback
```

## Build

1. Parts — [BOM](docs/bom_template.csv) and [compatibility](docs/parts_compatibility.md)
2. Print — 0.2 mm layer, 20% infill; [STL settings](hardware/stl/README.md)
3. Assemble — Palm, fingers, motor mounts; [tolerances](artifacts/notes/mechanical_tolerances.md)
4. Wire — [Pinout](hardware/wiring/pinout.md), [wiring notes](docs/wiring_notes.md)
5. Flash — [Firmware build](firmware/docs/build.md)
6. Test — [Smoke test](artifacts/tests/smoke_test_checklist.md)

**Full sequence:** [BUILD.md](BUILD.md)

## Design

CAD: [hardware/cad/](hardware/cad/). OpenSCAD parametric model + Python render script. Run `python3 render_hand.py` to regenerate PNGs.

## Repository

| Path | Contents |
|------|----------|
| `hardware/` | CAD, STL, wiring |
| `firmware/` | ESP32 source, build docs |
| `docs/` | Architecture, wiring, BOM, testing |
| `artifacts/` | Diagrams, procedures, notes |
| `logs/` | Test logs, metrics |

## Metrics

| Metric | Value |
|--------|-------|
| No-load current | ~0.3 A/motor |
| Peak current | ~1.4 A/motor |
| Stall cutoff | ~1.5 A |
| Grasp success | 18/20 trials |

*Replace with measured values from `/logs`.*

## Future

- Improved end-stops and torque margin
- ROS2 integration (optional)

---

[GitHub](https://github.com/Seaphant) · [LinkedIn](https://www.linkedin.com/in/william-nguyen-6046633aa/)
