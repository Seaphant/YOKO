# YOKO — Testing & Validation

Test plan templates and procedures. No numbers required in templates; fill with actual data when running tests.

---

## Test Plan Templates

### Current draw (no-load vs load)
- **Record:** V, I, tool (meter/shunt), method, ambient
- **Procedure:** Measure per motor at no-load; then under defined load; note peak and steady-state

### Stall behavior
- **Procedure:** Brief, safe stall; confirm cutoff triggers and recovery path
- **Record:** Trigger current, recovery time, any fault codes or serial messages

### Range of motion
- **Per finger:** Travel (degrees; measure and document in /logs), repeatability notes
- **Record:** Homing consistency, binding points, backlash

### Grasp trials
- **Record:** Object, number of trials, pass/fail, notes (e.g., slip, alignment)
- **Example placeholder:** Payload ~580 g [PROVISIONAL], Grasp success 18/20 [PROVISIONAL]

### Regression checklist
After any mechanical or firmware change:
- [ ] Power-on and serial banner
- [ ] Homing completes; limits respected
- [ ] Stall cutoff and recovery
- [ ] No binding, excessive heat, or unexpected sounds
- [ ] Update `/logs` with date and short description

---

## Replacing [PROVISIONAL] Values

1. Run tests per templates above; record in `/logs` using `test_log_template.md` format.
2. Fill `logs/001_baseline_metrics_SAMPLE.md` (or a dated copy) with **Actual Measurements**.
3. Update README and `docs/architecture.md` to replace [PROVISIONAL] with verified values and remove the tag.
4. See [CONTRIBUTING.md](../CONTRIBUTING.md) for rules: no fabricated numbers; use [TBD] or [PROVISIONAL] only.

**Link:** [../logs/](../logs/)
