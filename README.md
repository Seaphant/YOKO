# YOKO — 3D-Printed Robotic Hand

A CAD-designed, 3D-printed five-finger robotic hand with multi-joint fingers and swappable parts. ESP32 drives DC gear motors via PWM motor drivers; firmware includes calibration/homing limits, over-current stall cutoff, and FSR fingertip sensing for closed-loop grip-stop behavior.

### Conceptual views

**Homemade / iterative (3D-printed prototype)**  
![YOKO appearance](docs/images/yoko-appearance.png)

**CAD screenshots (conceptual—like Fusion 360 / Onshape viewport)**  
| View 1 | View 2 |
|--------|--------|
| ![YOKO CAD screenshot 1](docs/images/yoko-cad-screenshot-1.png) | ![YOKO CAD screenshot 2](docs/images/yoko-cad-screenshot-2.png) |

*Homemade: desk prototype, layer lines, wires; iterative build. CAD: conceptual viewport-style images. See [docs/images/](docs/images/) for files.*

---

## What I Built

### Mechanical
- 3D-printed hand: 5 fingers, multi-joint articulation, modular swappable parts
- CAD-designed; iterations on finger joints and tolerances to reduce binding and backlash
- Focus on tolerance tuning, linkage/joint iteration, and repeatability

### Electrical
- ESP32 as main controller
- DC gear motors driven via motor drivers (PWM)
- Calibration and homing limits; over-current / stall cutoff
- Fingertip FSR sensing for grip-stop behavior
- Current draw measured; peak wattage estimated (exact verification pending)

### Firmware
- PWM control for per-finger motor channels
- Calibration and homing routines with travel limits
- Safety: over-current detection and stall cutoff
- Debug workflow: serial logging and test markers for validation

---

## System Diagram

```mermaid
flowchart LR
  subgraph power
    B[Battery]
    F[Fuse / Limit]
    B --> F
  end
  subgraph control
    ESP[ESP32]
  end
  subgraph drive
    DRV[Motor Drivers]
    M[Motors x5]
    F --> DRV
    DRV --> M
    ESP -->|PWM| DRV
  end
  subgraph sense
    FSR[FSR Fingertips]
    FSR -->|grip stop| ESP
  end
  subgraph safety
    SC[Stall / Over-current Cutoff]
    DRV --> SC
    SC --> ESP
  end
```

**ASCII alternative:**

```
  [Battery] --> [Fuse] --> [Motor Drivers] --> [Motors x5]
       ^                      ^                    ^
       |                      |                    |
  [ESP32] ------------ PWM ---+                    |
       ^                      |                    |
       |                      +-- [Stall Cutoff] --+
       |
  [FSR Fingertips] --> grip-stop
```

---

## Firmware Highlights

- **PWM control:** Per-finger channels, rate limiting
- **Calibration / homing:** Travel limits, nonvolatile save (NVS; see firmware config)
- **Safety cutoff:** Over-current detection, stall cutoff (~1.5 A [PROVISIONAL])
- **Debug workflow:** Serial logs, test markers for `/logs` correlation

---

## Mechanical Highlights

- Tolerance tuning to reduce binding and backlash
- Linkage and joint iteration for smooth motion
- Modular, swappable parts for quick iteration and repair

---

## Testing & Validation

Procedures tracked in `/logs` and `/docs/testing_validation.md`. Metrics below are placeholders until verified; **replace with real measurements; see `/logs`.**

| Metric | Value | Status |
|--------|--------|--------|
| No-load current per motor | ~0.3 A | [PROVISIONAL] |
| Peak-load current per motor | ~1.4 A | [PROVISIONAL] |
| Stall/over-current cutoff threshold | ~1.5 A | [PROVISIONAL] |
| Full-hand peak power | ~45 W | [PROVISIONAL] |
| Payload tested | ~580 g | [PROVISIONAL] |
| Grasp success | 18/20 trials | [PROVISIONAL] |
| Open/close cycle time | ~1.6 s | [PROVISIONAL] |

Replace with verified measurements; see [Engineering Artifacts](#engineering-artifacts) and `/logs`.

---

## Engineering Artifacts

- **[/docs](docs/)** — Architecture, wiring notes, testing/validation, BOM template
- **[/logs](logs/)** — Test log template, smoke test example, baseline metrics (sample/provisional)
- **[/artifacts](artifacts/)** — Diagrams, notes, and test procedures (ASCII/Mermaid; no photo dependency)
  - **[/artifacts/diagrams](artifacts/diagrams)** — System block, finger linkage, power/wiring, homing state machine, FSR grip-stop flow, PWM control
  - **[/artifacts/notes](artifacts/notes)** — Design iterations, debugging workflow, calibration, safety cutoff, mechanical tolerances
  - **[/artifacts/tests](artifacts/tests)** — Smoke test checklist, current-draw procedure, grasp trial procedure, stall/recovery procedure, regression checklist

---

## Repo Tour

| Path | Contents |
|------|----------|
| `firmware/` | ESP32 code: `src/` (main, motor_control, calibration, safety, sensors, logging), `include/`, `docs/` (build, serial, modules) |
| `hardware/` | `cad/` (workflow, part naming), `stl/` (print settings, part list), `wiring/` (pinout, checklist) |
| `docs/` | Architecture, wiring, testing, BOM template |
| `logs/` | Test log template and example/sample logs |
| `artifacts/diagrams/` | System, finger, power, homing, grip-stop, PWM (Mermaid + ASCII) |
| `artifacts/notes/` | Design, debugging, calibration, safety, tolerances |
| `artifacts/tests/` | Smoke, current draw, grasp, stall/recovery, regression procedures |

---

## How to Reproduce

- **Print:** See [hardware/stl/README.md](hardware/stl/README.md) (e.g. 0.2 mm layer, 20% infill, PLA/PETG).
- **Wiring:** See [docs/wiring_notes.md](docs/wiring_notes.md) and [hardware/wiring/](hardware/wiring/) (pinout in wiring/pinout.md).
- **Firmware:** See [firmware/README.md](firmware/README.md) and [firmware/docs/build.md](firmware/docs/build.md); toolchain: PlatformIO, ESP-IDF, or Arduino IDE with ESP32.

---

## Future Work

- Torque margin and better end-stops
- Sensor calibration and sealed wiring
- Optional: ROS2 integration

---

## Contact

- **GitHub:** [Seaphant](https://github.com/Seaphant)
- **LinkedIn:** [William Nguyen](https://www.linkedin.com/in/william-nguyen-6046633aa/)
