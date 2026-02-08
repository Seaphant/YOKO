# YOKO — Regression Checklist

Run after any mechanical or firmware change to catch regressions before claiming success.

---

## When to Run

- After CAD/print/assembly change (e.g. new joint, tolerance, part swap).
- After firmware change (e.g. homing, cutoff, PWM, FSR logic).
- Before updating README or replacing [PROVISIONAL] with new numbers.

---

## Checklist

### Power and serial

- [ ] Power-on; serial banner visible; no unexpected resets.

### Homing

- [ ] Homing completes for all fingers.
- [ ] Limits respected; no continuous grind or stall during homing.
- [ ] Binding or uneven motion noted in `/logs` if present.

### Safety cutoff

- [ ] Brief stall applied; cutoff triggers.
- [ ] Recovery path works (clear fault, re-homing).
- [ ] Serial shows expected fault/recovery messages.

### Basic motion

- [ ] Open/close cycle runs without fault (cycle time ~1.6 s [PROVISIONAL] — measure if updating metrics).
- [ ] No excessive heat, grinding, or unexpected sounds.

### Grasp (subset)

- [ ] Run small set of grasp trials (e.g. 5 trials, one object).
- [ ] Pass/fail and notes recorded in `/logs`.
- [ ] If regression: fix before replacing [PROVISIONAL] or publishing new metrics.

### Logs

- [ ] New or updated entry in `/logs` with date, change, and result (use `test_log_template.md` format).
- [ ] Next steps written (e.g. "full current draw re-test", "re-print joint 2").

---

## Cross-Reference

- **Smoke test:** `artifacts/tests/smoke_test_checklist.md`
- **Validation:** `docs/testing_validation.md`
- **Log template:** `logs/test_log_template.md`
