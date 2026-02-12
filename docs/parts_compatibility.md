# YOKO — Parts Compatibility

Research-backed notes so the **parts and materials go together**. Use this with [bom_template.csv](bom_template.csv) and [BUILD.md](../BUILD.md) for an efficient, reproducible build.

---

## Voltage & logic levels

| Component | Requirement | Compatible with |
|-----------|-------------|------------------|
| ESP32 | 3.3 V logic outputs; ADC ref 3.3 V | All below when used as stated |
| Motor drivers (TB6612, DRV8833, L298) | Logic 2.7–5.5 V typical | ESP32 3.3 V GPIO → driver inputs OK |
| FSR | Excitation 3.3 V or 5 V; output &lt; VCC | 3.3 V from ESP32 + voltage divider → ADC |
| Motors | 4.5–12 V (driver-dependent) | Same battery as driver VM; stay within driver spec |

**Result:** One battery (6–12 V) for motor power; ESP32 powered via USB or separate 3.3 V regulator from same battery if needed. Common GND everywhere.

---

## Motor driver ↔ ESP32 ↔ motors

- **ESP32:** PWM 1 kHz, 8-bit (per `firmware/include/config.h`). Any GPIO capable of PWM is fine; pinout in [hardware/wiring/pinout.md](../hardware/wiring/pinout.md).
- **Driver:** Accepts PWM for speed. If driver is **dual-channel** (e.g. TB6612: 2 motors per IC), you need 2 such chips for 4 motors + 1 single-channel (or 3 chips for 5 motors). Alternatively use 5× single-channel driver boards.
- **Current:** Driver continuous current must be ≥ motor stall current. TB6612 ~1.2 A per channel; size motors so stall stays under that (or use a driver with higher rating).
- **Direction:** Firmware currently assumes one PWM per finger (speed). If your driver needs direction pins (e.g. IN1/IN2 on TB6612), add GPIOs in config and drive them in `motor_control.cpp`; pinout doc already notes “dual PWM (direction + speed)”.

**Conclusion:** ESP32 PWM → driver logic inputs; battery → driver VM → motors. Parts go together as long as voltage and current are within spec.

---

## FSR ↔ ESP32

- **FSR (e.g. Interlink FSR-402):** Variable resistance under force; no polarity. Use with a **voltage divider**: 3.3 V → FSR → ADC pin; other leg of FSR → 10 kΩ → GND. Junction (FSR–10kΩ) to ADC.
- **ESP32 ADC:** 0–3.3 V, 12-bit (0–4095) or 10-bit (0–1023). Firmware uses 10-bit; grip-stop threshold 512 in `config.h`. ADC1 preferred for WiFi coexistence (ADC2 used when WiFi active); pinout uses ADC1 for fingers 1–4 and ADC2 for 5 if needed.
- **Wiring:** Short, shielded or away from motor wires to reduce noise.

**Conclusion:** 3.3 V + 10 kΩ divider + FSR → ESP32 ADC is a standard, compatible stack.

---

## Mechanical (print + fasteners)

- **Filament:** PLA or PETG. PETG preferred for joints (toughness, wear). Same build works for both; temps in [hardware/stl/README.md](../hardware/stl/README.md).
- **Fasteners:** M2/M3 called out in BOM; match hole sizes in CAD/STL. Use same thread type for all joints to keep assembly efficient.

---

## Single verified stack (example)

| Role | Example part | Why it fits |
|------|------------------|-------------|
| MCU | ESP32-WROOM-32 dev board | 3.3 V logic, PWM, ADC, NVS for calibration |
| Motor driver | TB6612FNG breakout (2 ch) | 3.3 V logic, 4.5–13.5 V motor, ~1.2 A/ch |
| Motor | 6 V DC gear motor, &lt; 1 A stall | Within TB6612 current; 6 V within driver VM range |
| FSR | Interlink FSR-402 | 3.3 V + 10 kΩ → ADC; force range suitable for fingertips |
| Power | 7.4 V 2S LiPo or 6–12 V pack + fuse | Within driver VM; fuse protects wiring |

Using this stack keeps the build **efficient**: one BOM, one wiring scheme, one firmware pinout. Substitute equivalent parts that match the voltage/current/logic levels above.

---

## Cross-references

- **BOM:** [bom_template.csv](bom_template.csv)
- **Build order:** [BUILD.md](../BUILD.md)
- **Pinout:** [hardware/wiring/pinout.md](../hardware/wiring/pinout.md)
- **Wiring:** [wiring_notes.md](wiring_notes.md)
