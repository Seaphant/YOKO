**[SAMPLE / PROCEDURE ONLY — NO METRICS]**

---

# Smoke Test — Example Procedure

**Date:** 2025-06-28  
**Session:** Post-assembly, first power-on with homing and cutoff check.

---

## Steps

1. **Power-on, serial banner visible**
   - USB/serial connected; baud rate set; banner and version printed.
   - No unexpected resets or garbage.

2. **Homing routine completes; limits respected**
   - Homing sequence runs for all fingers.
   - Travel stops at configured limits; no continuous grinding or stall during homing.

3. **Manual jam applied; cutoff triggers; recovery confirmed**
   - One finger lightly jammed (safe, brief).
   - Over-current / stall cutoff triggers as expected.
   - After release, recovery path allows normal operation (e.g. re-homing or clear fault).

4. **Notes on binding, heat, unexpected sounds**
   - [ ] No binding at full range
   - [ ] No excessive motor or driver heat after 2–3 open/close cycles
   - [ ] No unexpected grinding or clicking

5. **Next steps checklist**
   - [ ] Tolerances: check joint clearance if binding observed
   - [ ] Lubrication: add if needed per joint type
   - [ ] Driver cooling: verify thermals under repeated load [TBD]

---

*This is a procedure template only; no metrics are claimed. Replace with actual observations when running the test.*
