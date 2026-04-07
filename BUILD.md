# YOKO — Build Guide

## BOM

| Item | Qty | Notes |
|------|-----|-------|
| ESP32 dev board | 1 | 3.3 V logic |
| DC gear motor | 5 | 6 V or 12 V; &lt; 1.2 A if TB6612 |
| Motor driver | 3–5 | TB6612, DRV8833, or L298 |
| FSR | 5 | Interlink FSR-402; 10 kΩ divider |
| Battery | 1 | 6–12 V; fuse recommended |
| Fasteners | — | M2/M3 |
| Filament | ~500 g | PLA or PETG |

Details: [bom.csv](docs/bom.csv), [parts_compatibility.md](docs/parts_compatibility.md)

## Order

1. **Parts** — Order BOM; match motor voltage to driver.
2. **Print** — [hardware/stl/README.md](hardware/stl/README.md)
3. **Assemble** — Palm, fingers, motor mounts; [mechanical_tolerances](artifacts/notes/mechanical_tolerances.md)
4. **Wiring** — [pinout](hardware/wiring/pinout.md), [wiring_notes](docs/wiring_notes.md)
5. **Firmware** — [build.md](firmware/docs/build.md); set pins in `config.h`
6. **Test** — [smoke_test_checklist](artifacts/tests/smoke_test_checklist.md)

## Reference

| Step | Doc |
|------|-----|
| BOM | [bom.csv](docs/bom.csv) |
| Print | [hardware/stl/README.md](hardware/stl/README.md) |
| Wiring | [hardware/wiring/](hardware/wiring/), [wiring_notes](docs/wiring_notes.md) |
| Firmware | [firmware/docs/build.md](firmware/docs/build.md) |
| Tests | [testing_validation](docs/testing_validation.md) |
