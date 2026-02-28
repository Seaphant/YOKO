# Mechanical Tolerances

## Binding

Binding at joints → uneven motion, stall, excess current. Iterate pin/boss clearance in CAD; test print; adjust; re-print. Log binding points (e.g. "joint 3 binds at 45°") in `/logs`.

## Backlash

Minimize for repeatable grip and homing. Iterate linkage/joint design; preload if needed. Log range-of-motion and repeatability in `/logs`.

## Swappable Parts

Modular finger segments, joints, motor mounts. Swap for iteration or repair without full reprint.

## Print & Assembly

Print: [hardware/stl/README.md](../../hardware/stl/README.md). Assembly: strain relief, cable routing in [wiring_notes](../../docs/wiring_notes.md).
