# YOKO — CAD

CAD workflow, file naming, and export to STL for 3D printing. CAD-designed hand with iterations on finger joints and tolerances.

---

## CAD Model (OpenSCAD)

- **yoko_robotic_hand.scad** — Parametric OpenSCAD model of the full assembly (5 fingers, 3 phalanxes each, joints, palm, motor mounts)
- Open [yoko_robotic_hand.scad](yoko_robotic_hand.scad) in OpenSCAD to view, render (F6), and export STL parts
- Individual part export: uncomment the relevant line at the bottom of the file, render, then File → Export as STL

## CAD Images

| File | Description |
|------|-------------|
| [cad-images/yoko-cad-viewport-1.png](cad-images/yoko-cad-viewport-1.png) | Front view — 5 fingers, phalanxes, joints, palm, motor mounts |
| [cad-images/yoko-cad-viewport-2.png](cad-images/yoko-cad-viewport-2.png) | Side view — profile of full assembly |

---

## Workflow

1. **Design:** CAD tool [TBD — e.g. Fusion 360, Onshape, FreeCAD]. Parts: finger segments (phalanxes), joints, motor mounts, base/palm.
2. **Iteration:** Tolerance tuning (pin/boss clearance), linkage geometry, joint type. Reduce binding and backlash; document in `../artifacts/notes/mechanical_tolerances.md` and `/logs`.
3. **Export:** Export parts to STL for printing. Naming convention below.
4. **Repo:** Proprietary CAD files (e.g. .f3d, .step) [TBD — store in repo or external]. STL list and notes in `../stl/`.

---

## File Naming

Suggested convention; adjust to match your tool:

- **Part type:** `yoko_<part>_v<version>.stl` — e.g. `yoko_phalanx_prox_v1.stl`, `yoko_joint_index_v2.stl`
- **Assembly:** e.g. `yoko_assembly_palm.step` for reference only (export from CAD)
- **Version:** Increment when tolerance or geometry changes; note in `/logs` or `../artifacts/notes/design_iterations.md`

---

## Parts Checklist

| Part category | Description | Notes |
|---------------|-------------|-------|
| Phalanx (prox/mid/dist) | Finger segments | Per finger; swappable |
| Joint | Pin/bearing/boss | Clearance per iteration; reduce binding (document in /logs) |
| Motor mount | Per finger | Driver/motor attachment |
| Palm / base | Hand base | Cable routing, strain relief |
| Connector / strain relief | Wiring | See `../wiring/` |

---

## Cross-Reference

- **Mechanical notes:** `../../artifacts/notes/mechanical_tolerances.md`, `design_iterations.md`
- **Diagrams:** `../../artifacts/diagrams/finger_linkage.md`
- **STL / print:** `../stl/README.md`
- **BOM:** `../../docs/bom_template.csv`
