# YOKO — Grasp Trial Procedure

Structured grasp trials: object, trials, pass/fail, notes. Used to replace [PROVISIONAL] grasp success and payload in README and `/logs`.

---

## Definitions

- **Pass:** Object secured without slip or drop for defined duration [TBD].
- **Fail:** Slip, drop, or inability to secure.
- **Payload:** Mass of object(s) tested [TBD units]. Example placeholder: ~580 g [PROVISIONAL].
- **Grasp success:** Pass count / total trials. Example placeholder: 18/20 [PROVISIONAL].

---

## Procedure

1. **Object:** Choose object(s); note shape, mass, surface (e.g. rigid, soft).
2. **Pose:** Hand orientation and object position [TBD] (repeatable fixture or freehand).
3. **Trials:** Run N trials (e.g. 20); record pass/fail per trial.
4. **Notes:** Slip direction, which finger slipped, FSR response, any binding or stall.
5. **Cycle time (optional):** Time from "close" command to stable grip; open/close cycle time ~1.6 s [PROVISIONAL] — replace with measured value.

---

## Logging

- Use `logs/test_log_template.md`: Date, object, trials, pass/fail count, notes.
- Update "Actual Measurements" in `logs/001_baseline_metrics_SAMPLE.md` for payload and grasp success.
- Update README metrics table and remove [PROVISIONAL] only after verification (see `CONTRIBUTING.md`).

---

## Regression

- After mechanical or firmware change, re-run a subset of grasp trials and document in `/logs` (see `regression_checklist.md`).

---

## Cross-Reference

- **Baseline (sample):** `logs/001_baseline_metrics_SAMPLE.md`
- **Docs:** `docs/testing_validation.md` (grasp trials template)
