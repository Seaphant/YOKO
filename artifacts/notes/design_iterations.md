# YOKO — Design Iteration Notes

Notes on mechanical and firmware iteration: tolerance tuning, joint binding, backlash, and swappable parts.

---

## Mechanical Iterations

### Tolerance tuning
- **Goal:** Reduce binding at joints; avoid over-tight or sloppy fit.
- **Approach:** CAD iterations on pin/boss clearance; print test pieces; measure fit.
- **Outcome:** Iterations on finger joints and tolerances to reduce binding and backlash (confirmed).
- **Status:** Ongoing; specific clearance values documented in /logs when finalized.

### Linkage and joint iteration
- **Goal:** Smooth motion, repeatable travel, minimal backlash.
- **Approach:** Adjust linkage geometry and joint type in CAD; print; test range of motion.
- **Outcome:** Multi-joint fingers with iteration on linkage/joint design (confirmed).
- **Status:** Binding points logged in test sessions; see `/logs`.

### Swappable parts
- **Goal:** Quick iteration and repair without full reprint.
- **Approach:** Modular design: finger segments, joints, and motor mounts as separate parts.
- **Outcome:** Modular swappable parts (confirmed).
- **Status:** Part numbering and BOM in `docs/bom_template.csv`; fill Link/Cost when sourced.

---

## Firmware Iterations

### Calibration / homing
- **Goal:** Reliable travel limits; repeatable home position.
- **Approach:** Homing routine drives to limit; nonvolatile save (NVS in firmware config).
- **Status:** Homing completes and limits respected (see smoke test in `/logs`).

### Safety cutoff
- **Goal:** Detect stall/over-current; disable drive; allow recovery.
- **Approach:** Current sense → threshold (~1.5 A [PROVISIONAL]); cutoff; recovery path.
- **Status:** Cutoff triggers and recovery confirmed in testing (see `/logs`).

---

## Cross-Reference

- **Diagrams:** `artifacts/diagrams/finger_linkage.md`, `homing_state_machine.md`, `grip_stop_flow.md`
- **Logs:** `logs/000_smoke_test_example.md`, `logs/001_baseline_metrics_SAMPLE.md`
- **Docs:** `docs/architecture.md`, `docs/testing_validation.md`
