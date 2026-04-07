# YOKO — 3D-Printed Robotic Hand

Five-finger robotic hand with 3D-printed mechanicals, ESP32 control, and closed-loop grip sensing. Modular design for iterative development.

https://github.com/Seaphant/YOKO/raw/main/docs/images/yoko-demo.mp4

## Overview

| Domain | Implementation |
|--------|----------------|
| **Mechanical** | 5 fingers × 3 phalanxes; pin joints; swappable parts; PLA/PETG |
| **Electrical** | ESP32, TB6612FNG drivers, 6 V N20 gear motors, FSR-402 fingertips |
| **Firmware** | PWM per finger, stall-based homing, EMA-filtered grip-stop, debounced overcurrent cutoff |

```
[Battery] → [Fuse] → [Motor Drivers] → [Motors ×5]
     ↑                    ↑
[ESP32] ←── PWM ──────────┘
     ↑
[FSR Fingertips] → grip-stop feedback
[Shunt + INA180] → overcurrent protection
```

## Build

1. Parts — [BOM](docs/bom.csv) and [compatibility](docs/parts_compatibility.md)
2. Print — 0.2 mm layer, 20% infill; [STL settings](hardware/stl/README.md)
3. Assemble — Palm, fingers, motor mounts; [tolerances](artifacts/notes/mechanical_tolerances.md)
4. Wire — [Pinout](hardware/wiring/pinout.md), [wiring notes](docs/wiring_notes.md)
5. Flash — [Firmware build](firmware/docs/build.md) / `cd firmware && pio run -e esp32`
6. Test — [Smoke test](artifacts/tests/smoke_test_checklist.md)

**Full sequence:** [BUILD.md](BUILD.md)

## Design

CAD: [hardware/cad/](hardware/cad/). OpenSCAD parametric model + Python render script. Run `python3 render_hand.py` to regenerate PNGs.

## Repository

| Path | Contents |
|------|----------|
| `hardware/` | CAD, STL, wiring |
| `firmware/` | ESP32 source (PlatformIO), build docs |
| `docs/` | Architecture, wiring, BOM, testing |
| `artifacts/` | Diagrams, procedures, notes |
| `logs/` | Test logs, metrics |

## Measured Performance

| Metric | Value | Source |
|--------|-------|--------|
| No-load current | 0.28–0.34 A/motor | [Log 002](logs/002_baseline_current_draw.md) |
| Peak current (grip) | 1.32–1.48 A/motor | [Log 002](logs/002_baseline_current_draw.md) |
| Stall cutoff | Trips at ~1.65–1.82 A | [Log 002](logs/002_baseline_current_draw.md) |
| Grip-stop trigger | 5/5 reliable | [Log 002](logs/002_baseline_current_draw.md) |
| Homing (all fingers) | ~11.2 s total | [Log 002](logs/002_baseline_current_draw.md) |
| Grasp success | 18/20 trials | [Grasp procedure](artifacts/tests/grasp_trial_procedure.md) |

## CI

[![Firmware Build](https://github.com/Seaphant/YOKO/actions/workflows/build.yml/badge.svg)](https://github.com/Seaphant/YOKO/actions/workflows/build.yml)

Firmware compiles on every push via GitHub Actions + PlatformIO.

## About This Project

Solo build — design, electronics, firmware, and testing all done by one person. See [ABOUT.md](ABOUT.md) for the full story: timeline, hardest problems, and what I'd do differently.

## Future

- Magnetic encoders for closed-loop position control
- Custom PCB to replace breadboard wiring
- ROS2 hardware interface for integration with vision/planning stacks

---

[GitHub](https://github.com/Seaphant) · [LinkedIn](https://www.linkedin.com/in/william-nguyen-6046633aa/)
