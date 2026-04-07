# About YOKO

## Who

Built by **William Nguyen** — engineering student, maker, and robotics enthusiast.

- [GitHub](https://github.com/Seaphant)
- [LinkedIn](https://www.linkedin.com/in/william-nguyen-6046633aa/)

## Why

I wanted to build something that combined mechanical design, electronics, and firmware into a single integrated system. A robotic hand hits all three: the geometry is non-trivial (five independent kinematic chains sharing a palm), the electrical system mixes power and analog sensing, and the firmware has to coordinate real-time motor control with safety-critical current limiting.

YOKO started as a way to go deeper than classroom projects typically allow — to own every layer from CAD to compiled binary, make real measurements, and iterate on actual hardware instead of simulation alone.

## Timeline

- **Initial design and CAD** — parametric OpenSCAD model, first prints, joint clearance iteration
- **Electronics bring-up** — ESP32 + TB6612 wiring, FSR voltage dividers, shunt current sense
- **Firmware v0.1** — basic PWM, manual open/close via serial commands
- **Firmware v0.2** — homing state machine, EMA-filtered FSR grip-stop, debounced overcurrent cutoff, NVS persistence, structured telemetry logging
- **Testing and validation** — baseline current draw characterization, grasp trials, safety cutoff verification

## What was hard

**Homing without encoders.** The N20 gear motors don't have position feedback, so homing relies on driving each finger slowly toward its mechanical stop and detecting the current spike when it stalls. Getting the threshold right required balancing sensitivity (catch the stall early) against false positives (ignore inrush and friction bumps). The debounce counter and separate homing current threshold (`HOMING_STALL_MA`) came out of that iteration.

**FSR noise from PWM.** The motor PWM couples into the ADC readings through the shared ground plane. Raw ADC reads would spike by 200+ counts on motor transitions, causing false grip-stop triggers. The EMA filter solved it, but tuning the alpha was a back-and-forth between response latency (too much smoothing and grip-stop fires late) and noise rejection.

**Mechanical tolerances.** 3D-printed pin joints need enough clearance to rotate freely but not so much that the finger wobbles under load. I went through three clearance values (0.15 mm, 0.2 mm, 0.25 mm) before settling on 0.2 mm for PLA and 0.25 mm for PETG, which shrinks slightly differently.

## What I'd do differently

- **Add encoders.** Stall-based homing works but it's slow and stresses the gears. Magnetic encoders on each motor would enable closed-loop position control and faster homing.
- **Custom PCB.** The current build is breadboarded. A purpose-built PCB with integrated motor drivers, current sense, and FSR conditioning would reduce wiring errors and noise.
- **ROS2 integration.** Right now the hand is standalone with serial control. Wrapping it as a ROS2 hardware interface would make it composable with vision, planning, and other robotics stacks.

## Demo

The demo video is in the repo at [`docs/images/yoko-demo.mp4`](docs/images/yoko-demo.mp4).
