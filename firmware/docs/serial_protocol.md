# YOKO — Serial Protocol / Debug Output (v0.2)

Serial output format for debugging, control, and correlation with repo `/logs`. Baud: 115200 (`config.h` `SERIAL_BAUD`).

---

## Banner (on boot)

```text
[YOKO] ============================
[YOKO]  YOKO Robotic Hand v0.2
[YOKO]  ESP32 / 5-finger PWM+FSR
[YOKO] ============================
[YOKO] Loop interval: 10 ms
```

- Printed once after `logging_banner()`.
- Use to confirm power-on and firmware version in `/logs`.

---

## State Messages

```text
[YOKO] STATE <state>
```

- **state:** `boot_complete`, `homing_start`, `homing_complete`, `safety_cutoff`, `safety_clear`, `cal_fault`
- Use to confirm homing completion, cutoff trigger, and recovery in smoke test and stall procedure.

---

## Debug Output

```text
[YOKO] <message>
```

- Homing progress: `Homing finger 0`, `Finger 0 limit at duty 80 (stall 812 mA)`
- NVS: `NVS: loaded limits for 5 fingers`, `NVS: saved limits`

---

## Telemetry

```text
[YOKO] TEL CH<n> duty=<int> fsr=<int> mA=<int>
```

Emitted every 500 ms (one line per finger) with current duty, filtered FSR reading, and bus current.

---

## Test Markers

For correlation with `logs/test_log_template.md` and test procedures in `artifacts/tests/`:

```text
[YOKO] TEST_START <test_id>
...
[YOKO] TEST_END <test_id>
```

- **test_id:** e.g. `smoke_001`, `baseline`, `grasp_trial_1`

---

## Serial Commands (v0.2)

Line-based input (CR or LF terminated). Processed in `serial_cmd.cpp`.

| Command | Response | Effect |
|---------|----------|--------|
| `help` | `[YOKO] CMD commands: help \| status \| open <duty> \| close \| home \| clear` | List commands |
| `status` | `[YOKO] CMD status mode=<RUN\|HOMING\|FAULT> current_mA=<int> ch0=<duty>/<limit> ...` | Print mode, current, per-finger duty/limit |
| `open <duty>` | `[YOKO] CMD open duty=<int>` | Drive all fingers to `<duty>` (0-255); defaults to 255 |
| `close` | `[YOKO] CMD close` | Set all fingers to zero duty |
| `home` | `[YOKO] CMD home` | Stop motors and restart homing sequence |
| `clear` | `[YOKO] STATE safety_clear` | Clear latched overcurrent fault (if current is safe) |

---

## Cross-Reference

- **Logging module:** `../include/logging.h`, `../src/logging.cpp`
- **Serial command module:** `../include/serial_cmd.h`, `../src/serial_cmd.cpp`
- **Tests:** `../../artifacts/tests/` (smoke, stall, grasp)
- **Log template:** `../../logs/test_log_template.md`
