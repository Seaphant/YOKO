# Contributing to YOKO

Guidelines for adding logs, replacing provisional values, and keeping the repo honest.

---

## Adding or Updating Logs

- **Filename format:** `NNN_short_desc.md` (e.g. `002_grasp_trials.md`) or dated: `YYYY-MM-DD_short_desc.md`
- Place new logs in `/logs`
- Use the structure from `logs/test_log_template.md`: Date, Change, Hypothesis, Test Method, Results, Next Steps, Links
- Add **Measurement notes** (tool, units, ambient, repeat count) where applicable

---

## Replacing [PROVISIONAL] Values

1. Run tests per `docs/testing_validation.md`; record in `/logs` with the test log format.
2. Fill the **Actual Measurements** section (e.g. in `logs/001_baseline_metrics_SAMPLE.md` or a dated copy) with real values.
3. In README and `docs/architecture.md`, replace the provisional number with the verified value and **remove** the `[PROVISIONAL]` tag.
4. Add a short note that the value was verified and when (e.g. in the log file or README).

---

## Updating README / Badges After Verification

- Replace the metrics table in README with verified numbers and remove [PROVISIONAL].
- Optionally add a “Verified on YYYY-MM-DD” or “See logs/001_…” note.
- Do **not** add badges or claims that imply verification until values are actually measured and documented in `/logs`.

---

## Rule: No Fabricated Numbers

- Do **not** introduce fabricated or guessed metrics.
- Use **[TBD]** for unknown or not-yet-defined items.
- Use **[PROVISIONAL]** only for placeholder values that are explicitly marked as such and will be replaced by real measurements.
- When in doubt, leave a value as [TBD] or [PROVISIONAL] and document the plan to verify in `/logs`.
