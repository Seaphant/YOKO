# YOKO — STL and Print

STL part list, print settings, and orientation notes. 3D-printed parts for hand, joints, and mounts.

---

## Part List

| STL file | Part | Qty | Notes |
|----------|------|-----|-------|
| yoko_phalanx_prox_v1.stl | Phalanx proximal | 5 | Per finger |
| yoko_phalanx_mid_v1.stl | Phalanx middle | 5 | Per finger |
| yoko_phalanx_dist_v1.stl | Phalanx distal | 5 | Per finger |
| yoko_joint_v1.stl | Joint | 5 | Pin/bearing clearance; one per finger |
| yoko_motor_mount_v1.stl | Motor mount | 5 | Per finger |
| yoko_palm_base_v1.stl | Palm / base | 1 | Cable routing |
| (optional) | Strain relief, covers | — | Add as designed |

Add or rename files as parts are finalized. STL files may live in this folder or in an external drive; keep naming consistent (e.g. `yoko_<part>_v<N>.stl`).

---

## Print Settings

- **Printer:** FDM (e.g. Creality Ender, Prusa); build volume sufficient for palm and longest phalanx.
- **Material:** PLA or PETG (PETG preferred for joints and wear).
- **Layer height:** 0.2 mm (0.16 mm for finer detail if needed).
- **Infill:** 20% default; 30–40% for joints and motor mounts.
- **Supports:** As needed for overhangs; minimize on joint surfaces to reduce post-process.
- **Temperature:** Nozzle 200–220 °C (PLA) or 230–250 °C (PETG); bed 60 °C (PLA) or 70–80 °C (PETG).
- **Speed:** 50–60 mm/s default; reduce for small parts or first layer.

Generic settings; adjust per material and part. Document any changes in `/logs` or `../../artifacts/notes/mechanical_tolerances.md`.

---

## Orientation and Supports

- **Orientation:** Minimize overhangs and support where possible; preserve strength along load direction (e.g. joint pins).
- **Support:** Use for steep overhangs; remove and sand joint surfaces for smooth motion.
- **Post-process:** Sanding, clearance ream for pin holes if needed; document in `../../artifacts/notes/mechanical_tolerances.md`.

---

## Cross-Reference

- **CAD:** `../cad/README.md`
- **BOM:** `../../docs/bom_template.csv` (3D filament row)
- **Design iterations:** `../../artifacts/notes/design_iterations.md`
