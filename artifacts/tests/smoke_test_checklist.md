# YOKO — Smoke Test Checklist

Quick post-assembly or post-change check: power-on, homing, cutoff, and basic behavior. Use this with serial connected and `/logs` ready.

---

## Pre-Test

- [ ] Power disconnected; serial cable connected; baud set [TBD]
- [ ] Moving parts and cables clear of pinch points
- [ ] Battery / supply within spec [TBD]

---

## Steps

### 1. Power-on and serial banner

- [ ] Apply power
- [ ] Serial banner visible; no garbage or unexpected resets
- [ ] Note banner text or version in `/logs` if first run

### 2. Homing routine

- [ ] Start homing (command or auto [TBD])
- [ ] All fingers drive toward limit
- [ ] Travel stops at limits; no continuous grinding or stall during homing
- [ ] Note any binding or uneven motion in `/logs`

### 3. Stall / over-current cutoff

- [ ] Apply brief, safe manual jam to one finger
- [ ] Cutoff triggers (PWM off or fault state)
- [ ] Serial shows fault or cutoff message
- [ ] After release, recovery path allows normal operation (e.g. clear fault, re-homing)
- [ ] Record trigger and recovery in `/logs`

### 4. Binding, heat, sounds

- [ ] No binding at full range of motion
- [ ] No excessive motor or driver heat after 2–3 open/close cycles
- [ ] No unexpected grinding or clicking
- [ ] If any issue: note in `/logs` with finger/joint and next steps (tolerances, lubrication, cooling [TBD])

---

## Post-Test

- [ ] Log entry created or updated in `/logs` (use `test_log_template.md` format)
- [ ] Next steps written (e.g. "re-run current draw test", "adjust joint 3 clearance")

---

## Cross-Reference

- **Procedure (sample):** `logs/000_smoke_test_example.md`
- **Regression:** `artifacts/tests/regression_checklist.md`
- **Docs:** `docs/testing_validation.md`
