# YOKO — Serial Protocol / Debug Output

Serial output format for debugging and correlation with repo `/logs`. Baud [TBD] (default 115200 in config.h).

---

## Banner (on boot)

```text
YOKO v[TBD] [build info]
```

- Printed once after `logging_banner()`.
- Use to confirm power-on and firmware version in `/logs`.

---

## Test Markers

For correlation with `logs/test_log_template.md` and test procedures in `artifacts/tests/`:

```text
TEST_START <test_id>
...
TEST_END <test_id>
```

- **test_id:** e.g. `smoke_001`, `baseline`, `grasp_trial_1`
- Log timestamp or marker in "Links" / "Measurement notes" when filling `/logs`.

---

## State Messages

```text
STATE <state>
```

- **state:** e.g. `homing_start`, `homing_complete`, `safety_cutoff`, `safety_clear`, `cal_fault`
- Use to confirm homing completion, cutoff trigger, and recovery in smoke test and stall procedure.

---

## Debug [TBD]

- Optional: current (mA), duty per channel, FSR raw values.
- Format [TBD] — e.g. `DEBUG current=1200 duty=128,128,... fsr=100,200,...`
- Enable/disable via compile flag or runtime [TBD].

---

## Cross-Reference

- **Logging module:** `../include/logging.h`, `../src/logging.cpp`
- **Tests:** `../../artifacts/tests/` (smoke, stall, grasp)
- **Log template:** `../../logs/test_log_template.md`
