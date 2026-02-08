# YOKO — Current Draw Test Procedure

Measure no-load and under-load current per motor (or per driver). Used to replace [PROVISIONAL] values in README and `/logs`.

---

## Equipment

- **Measurement:** Inline meter in series with motor supply, or shunt + DMM [TBD tool]
- **Record:** Tool, range, units (A), ambient (temp/notes), repeat count

---

## Safety

- Disconnect power before changing wiring for measurement.
- Ensure meter/shunt rating exceeds expected peak current (~1.4 A [PROVISIONAL] per motor; stall ~1.5 A [PROVISIONAL]).
- Isolate moving parts during test.

---

## Procedure

### No-load current

1. Wire meter/shunt in series with one motor (or driver output) [TBD which point].
2. Power on; run homing.
3. Command motor to run at steady speed with no mechanical load (e.g. finger free).
4. Record current (A); repeat per finger or per channel.
5. Note: No-load current per motor ~0.3 A [PROVISIONAL] — replace with measured value in `/logs` and README.

### Under-load / peak current

1. Same setup; apply defined load (e.g. grasp object, or resistive load per driver spec).
2. Record peak and steady-state current.
3. Note: Peak-load current per motor ~1.4 A [PROVISIONAL] — replace with measured value.

### Full-hand peak power

1. Measure supply voltage (V) and total current (all motors) at peak load.
2. Power (W) = V × I.
3. Note: Full-hand peak power ~45 W [PROVISIONAL] — replace with measured value.

---

## Logging

- Use `logs/test_log_template.md` format: Date, Change, Hypothesis, Test Method, Results, Next Steps.
- Fill "Actual Measurements" in `logs/001_baseline_metrics_SAMPLE.md` (or dated copy).
- Update README and remove [PROVISIONAL] only after verification (see `CONTRIBUTING.md`).

---

## Cross-Reference

- **Baseline (sample):** `logs/001_baseline_metrics_SAMPLE.md`
- **Docs:** `docs/testing_validation.md`, `docs/wiring_notes.md` (measurement setup)
