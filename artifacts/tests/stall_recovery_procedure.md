# YOKO — Stall / Over-Current Cutoff and Recovery Procedure

Verify stall detection, cutoff trigger, and recovery path. Safe, brief stall only.

---

## Safety

- **Brief stall only:** Apply manual jam for short duration; release immediately when cutoff triggers.
- Keep hands and cables clear of moving parts.
- Ensure cutoff threshold is enabled (~1.5 A [PROVISIONAL]; replace with verified value in `/logs`).

---

## Procedure

### 1. Cutoff trigger

1. Power on; run homing.
2. Command one finger to close (or open).
3. Apply safe, brief jam (e.g. block motion with finger or tool).
4. **Expected:** Current rises; cutoff triggers; PWM disabled or driver in safe state.
5. **Record:** Serial fault/cutoff message; current at trigger if measured (see current_draw_procedure).
6. Note: Stall cutoff threshold ~1.5 A [PROVISIONAL] — replace with measured value in `/logs`.

### 2. Recovery

1. Release jam.
2. Clear fault (command or auto; see firmware safety_clear_fault).
3. **Expected:** System returns to idle or allows re-homing.
4. Re-run homing; confirm limits still respected.
5. **Record:** Recovery path and time in `/logs`.

### 3. Repeat (optional)

- Repeat for other fingers to confirm per-channel cutoff.
- Do not hold stall; allow cooldown if needed (e.g. 5–10 s before retry).

---

## Logging

- Use `logs/test_log_template.md`: Date, "Stall recovery", hypothesis, method, results (trigger + recovery), next steps.
- Update `logs/001_baseline_metrics_SAMPLE.md` "Stall cutoff threshold" when verified.
- Update README and remove [PROVISIONAL] per `CONTRIBUTING.md`.

---

## Cross-Reference

- **Smoke test:** `artifacts/tests/smoke_test_checklist.md` (cutoff step)
- **Sample log:** `logs/000_smoke_test_example.md`
- **Docs:** `docs/architecture.md` (safety), `docs/testing_validation.md`
