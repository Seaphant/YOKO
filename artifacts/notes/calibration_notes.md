# YOKO — Calibration and Homing Notes

Notes on homing routine, travel limits, and calibration workflow.

---

## Homing Routine

- **Purpose:** Establish known position (limits) for each finger before normal operation.
- **Behavior:** Drive each finger toward limit (e.g. open or closed end); detect limit; stop; optionally repeat for other end [TBD].
- **Evidence:** Homing routine completes; limits respected (see smoke test in `/logs`).
- **Diagram:** `artifacts/diagrams/homing_state_machine.md`.

## Travel Limits

- **Definition:** Min/max position or angle per finger [TBD units].
- **Use:** Prevent over-travel; define "open" and "closed" for grasp trials.
- **Storage:** Nonvolatile save [TBD] so limits persist across power cycles.
- **Update:** Re-run homing after mechanical change (e.g. joint swap, tolerance fix).

## Calibration Workflow

1. Power on; ensure serial connected.
2. Run homing (command or auto on boot [TBD]).
3. Confirm all fingers reach limits without stall; note any binding in `/logs`.
4. If limits change (e.g. new part), re-homing required before next test.
5. Optional: store limits to NVS/EEPROM [TBD] and document in firmware docs.

---

## Cross-Reference

- **Diagrams:** `artifacts/diagrams/homing_state_machine.md`
- **Logs:** `logs/000_smoke_test_example.md` (homing step)
- **Docs:** `docs/architecture.md` (calibration module), `docs/testing_validation.md`
