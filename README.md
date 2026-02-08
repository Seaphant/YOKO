# YOKO — 3D-Printed Robotic Hand

A CAD-designed, 3D-printed five-finger robotic hand with multi-joint fingers and swappable parts. ESP32 drives DC gear motors via PWM motor drivers; firmware includes calibration/homing limits, over-current stall cutoff, and FSR fingertip sensing for closed-loop grip-stop behavior.

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
- **Calibration / homing:** Travel limits, nonvolatile save [TBD]
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
- **[/artifacts](artifacts/)** — Diagrams, tests, notes (ASCII/Mermaid)

---

## Repo Tour

| Path | Contents |
|------|----------|
| `firmware/` | Source, headers, firmware docs |
| `hardware/` | CAD, STL, wiring |
| `docs/` | Architecture, wiring, testing, BOM template |
| `logs/` | Test log template and example/sample logs |
| `artifacts/` | Diagrams, test artifacts, notes |

---

## How to Reproduce

- **Print:** Generic settings [TBD]
- **Wiring:** See [docs/wiring_notes.md](docs/wiring_notes.md) [TBD]
- **Firmware toolchain:** [TBD — PlatformIO / ESP-IDF / Arduino IDE]; do not overclaim

---

## Future Work

- Torque margin and better end-stops [TBD]
- Sensor calibration and sealed wiring [TBD]
- Optional: ROS2 integration [TBD]

---

## Contact

- **GitHub:** [Seaphant](https://github.com/Seaphant)
- **LinkedIn:** [William Nguyen](https://www.linkedin.com/in/william-nguyen-6046633aa/)
