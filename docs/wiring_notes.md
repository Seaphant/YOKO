# YOKO — Wiring Notes

Generic wiring and safety notes. No specific part numbers unless confirmed.

---

## Power Path Overview

1. **Battery** → main supply
2. **Fuse / current limit** [recommended] → protection before drivers
3. **Motor drivers** → PWM from ESP32, power to motors
4. **Motors** → one channel per finger (or as designed)

Keep wires short where possible; use strain relief at connectors and moving joints.

---

## Grounds

- Single common ground reference between battery, ESP32, and motor drivers
- Avoid ground loops; star or single-point ground where practical
- Shield or separate signal lines from high-current motor paths if needed

---

## Connectors & Strain Relief

- Secure connectors at hand base and at driver/ESP32 side
- Strain relief at flex points to avoid broken strands and intermittent faults
- Label or color-code channels for easier debugging

---

## Safety

- **Isolate moving parts** during power-on tests; keep fingers and cables clear of pinch points
- **Disconnect power** before mechanical work (e.g., joint adjustment, part swap)
- **Over-current / stall cutoff** is enabled in firmware; ensure it is tested and not disabled during normal use
- Fuse or current limit on the main power path is recommended

---

## Current Measurement Setup

- **Options:** Inline meter in series with motor supply, or shunt + DMM [TBD tool]
- **Placement:** Per-motor or per-driver, as needed for no-load vs peak vs stall tests
- **Record:** Tool, range, units, and ambient conditions in `/logs` for each test

---

## Status

- Specific part numbers, wire gauges, and connector types: [TBD] until confirmed
- See `/logs` for test dates and results; see `bom_template.csv` for BOM placeholders.
