# YOKO — Mechanical Tolerances and Binding Notes

Notes on joint clearance, backlash, binding, and print/assembly.

---

## Binding

- **Observed:** Binding at joints can cause uneven motion, stall, or excess current.
- **Approach:** CAD iterations on pin/boss clearance; test print; adjust tolerance; re-print. Document binding points in `/logs` (e.g. "joint 3 binds at 45°").
- **Outcome:** Iterations on finger joints and tolerances to reduce binding (confirmed).
- **Specific values:** Clearance and print settings [TBD] when finalized.

## Backlash

- **Goal:** Minimize backlash for repeatable grip and homing.
- **Approach:** Linkage and joint design iteration; preload or fit [TBD]; measure repeatability in range-of-motion tests.
- **Outcome:** Iterations to reduce backlash (confirmed).
- **Measurement:** Range-of-motion and repeatability notes in `docs/testing_validation.md`; fill in `/logs` when run.

## Swappable Parts

- **Design:** Modular finger segments, joints, motor mounts so parts can be swapped without full reprint.
- **Use:** Quick iteration (e.g. try different clearance on one joint); repair (replace one phalanx).
- **BOM:** See `docs/bom_template.csv`; part names and quantities [TBD] when locked.

## Print and Assembly

- **Print settings:** Generic settings [TBD]; material and layer height in BOM or hardware docs when confirmed.
- **Assembly:** Sequence and torque [TBD]; strain relief and cable routing in `docs/wiring_notes.md`.

---

## Cross-Reference

- **Diagrams:** `artifacts/diagrams/finger_linkage.md`
- **Logs:** `logs/000_smoke_test_example.md` (binding/heat/sounds), `logs/001_baseline_metrics_SAMPLE.md`
- **Docs:** `docs/testing_validation.md` (range-of-motion, regression), `docs/bom_template.csv`
