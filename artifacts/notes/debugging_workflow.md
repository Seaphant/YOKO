# YOKO — Debugging Workflow

How debugging and validation are done: serial logs, test markers, and correlation with `/logs`.

---

## Serial Debug

- **Tool:** USB/serial from ESP32; baud rate [TBD].
- **Content:** Banner on boot; state changes (idle, homing, running, fault); PWM or duty summaries [TBD]; FSR raw or scaled [TBD].
- **Use:** Confirm power-on, homing completion, and fault conditions during tests.

## Test Markers

- **Goal:** Tie serial output to specific test runs in `/logs`.
- **Approach:** Print a unique marker at start/end of a test (e.g. `TEST_START smoke_001`, `TEST_END baseline`).
- **Use:** When filling `logs/test_log_template.md`, note timestamp or marker so log lines can be matched to serial captures.

## Correlation with Logs

1. Run test per procedure in `artifacts/tests/` or `docs/testing_validation.md`.
2. Capture serial output (copy/paste or log file).
3. In `/logs`, create or update entry: date, change, hypothesis, test method, results, next steps.
4. In "Links" or "Measurement notes", reference serial marker or timestamp.
5. Replace [PROVISIONAL] in README/logs only after verified measurements (see `CONTRIBUTING.md`).

---

## Typical Debug Session

1. **Reproduce:** Power on; run homing; run one closed-loop action (e.g. close until FSR stop).
2. **Observe:** Serial banner, homing messages, any fault or stall message.
3. **Log:** Note in `/logs` what was seen; add next steps (e.g. "re-check joint 3 binding").
4. **Iterate:** Mechanical or firmware change → re-run smoke/regression (see `artifacts/tests/regression_checklist.md`).

---

## Cross-Reference

- **Tests:** `artifacts/tests/smoke_test_checklist.md`, `regression_checklist.md`
- **Logs:** `logs/test_log_template.md`
- **Docs:** `docs/testing_validation.md`, `docs/architecture.md` (logging module)
