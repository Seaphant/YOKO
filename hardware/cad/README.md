# CAD

**OpenSCAD:** [yoko_robotic_hand.scad](yoko_robotic_hand.scad) — parametric model. Open in OpenSCAD, F6 to render, File → Export as STL. Uncomment part lines at bottom for individual export.

**Python render:** [render_hand.py](render_hand.py) — builds mesh, exports STL + PNG. Run `python3 render_hand.py` (requires trimesh, numpy, matplotlib).

**Outputs:** [cad-images/](cad-images/) — assembly STL, viewport PNGs.

**STL naming:** `yoko_<part>_v<N>.stl` — e.g. `yoko_phalanx_prox_v1.stl`. See [hardware/stl/](../stl/README.md).
