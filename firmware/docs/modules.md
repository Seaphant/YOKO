# YOKO — Firmware Modules Overview

Short overview of each module; full architecture in repo root `docs/architecture.md`.

---

## motor_control

- **Path:** `../src/motor_control.cpp`, `../include/motor_control.h`
- **Role:** PWM to motor drivers; per-finger channels; rate limiting to smooth motion and limit peak current.
- **API:** `motor_control_init()`, `motor_control_set_duty(channel, duty)`, `motor_control_update()`, `motor_control_stop_all()`.
- **Config:** FINGER_COUNT, PWM_FREQ_HZ (1 kHz), PWM_RESOLUTION_BITS (8) in `config.h`.
- **Diagram:** `../../artifacts/diagrams/pwm_control_timing.md`

---

## calibration

- **Path:** `../src/calibration.cpp`, `../include/calibration.h`
- **Role:** Homing routine; travel limits; NVS save (NVS_NAMESPACE, NVS_KEY_LIMITS in config.h).
- **State machine:** Idle → HomingRequest → MovingToLimit → AtLimit → HomingComplete (or Fault on over-current).
- **API:** `calibration_init()`, `calibration_start_homing()`, `calibration_update()`, `calibration_is_ready()`, `calibration_get_state()`.
- **Diagram:** `../../artifacts/diagrams/homing_state_machine.md`

---

## safety

- **Path:** `../src/safety.cpp`, `../include/safety.h`
- **Role:** Over-current detection; stall cutoff (~1.5 A [PROVISIONAL]); clear fault for recovery.
- **API:** `safety_init()`, `safety_read_current_mA()`, `safety_update()`, `safety_in_fault()`, `safety_clear_fault()`.
- **Config:** SAFETY_CURRENT_THRESHOLD_MA in `config.h` — replace with verified value (see `/logs`).
- **Notes:** `../../artifacts/notes/safety_cutoff_notes.md`

---

## sensors

- **Path:** `../src/sensors.cpp`, `../include/sensors.h`
- **Role:** FSR read; grip-stop threshold for closed-loop stop when contact detected.
- **API:** `sensors_init()`, `sensors_read_fsr(channel)`, `sensors_update()`, `sensors_grip_stop_triggered()`.
- **Diagram:** `../../artifacts/diagrams/grip_stop_flow.md`

---

## logging

- **Path:** `../src/logging.cpp`, `../include/logging.h`
- **Role:** Serial banner; test markers (TEST_START / TEST_END); state messages for `/logs` correlation.
- **API:** `logging_banner()`, `logging_test_start(id)`, `logging_test_end(id)`, `logging_state(state)`, `logging_debug(msg)`.
- **Protocol:** `serial_protocol.md`

---

## Cross-Reference

- **Architecture:** `../../docs/architecture.md`
- **Build:** `build.md`
- **Artifacts:** `../../artifacts/diagrams/`, `../../artifacts/notes/`
