# YOKO — Safety and Over-Current Cutoff Notes

Notes on over-current detection, stall cutoff, and safe operation.

---

## Over-Current / Stall Cutoff

- **Purpose:** Detect stall or excessive current; disable drive to protect hardware and allow recovery.
- **Threshold:** ~1.5 A [PROVISIONAL] per motor or per driver; to be replaced with verified value (see `/logs`).
- **Behavior:** When current exceeds threshold, PWM disabled or drivers put in safe state; fault reported (e.g. serial); recovery path: clear fault, then re-homing.
- **Evidence:** Manual jam applied in testing; cutoff triggers; recovery confirmed (see smoke test in `/logs`).

## Thermal Cooldown

- **Status:** Thermal cooldown or derating not yet implemented; optional future addition.
- **Future:** Monitor driver/MCU temperature; reduce duty or pause if over limit.

## Safe Operation

- **Before mechanical work:** Disconnect power; avoid moving parts under power.
- **During test:** Isolate fingers and cables from pinch points; keep hands clear.
- **Power path:** Fuse or current limit recommended on battery side (see `docs/wiring_notes.md`).
- **Serial:** Use fault messages to confirm cutoff and recovery; log in `/logs`.

---

## Cross-Reference

- **Diagrams:** `artifacts/diagrams/system_block.md` (safety block)
- **Logs:** `logs/000_smoke_test_example.md` (cutoff step), `logs/001_baseline_metrics_SAMPLE.md` (threshold [PROVISIONAL])
- **Docs:** `docs/architecture.md` (safety module), `docs/wiring_notes.md`
