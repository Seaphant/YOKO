# Baseline Current Draw — Initial Measurements

**Date:** 2026-03-20  
**Operator:** William Nguyen  
**Session:** Post-assembly current characterization, all 5 fingers wired.

---

## Setup

- **MCU:** ESP32-WROOM-32 DevKitC  
- **Drivers:** 3× TB6612FNG breakout (2 ch each, 5 channels used)  
- **Motors:** 5× N20 DC gear motor, 6 V 100 RPM  
- **Power:** Bench supply set to 6.0 V, current-limited at 5.0 A  
- **Measurement:** Uni-T UT61E DMM on motor bus, serial telemetry via USB at 115200 baud  
- **Firmware:** Commit `b2765ed`, homing enabled, safety threshold 1500 mA  
- **Ambient:** ~22 °C, indoor bench

---

## Results

| Metric                     | Value     | Method                        | Notes                              |
|----------------------------|-----------|-------------------------------|------------------------------------|
| No-load current (per motor)| 0.28–0.34 A | DMM on individual channel    | Averaged over 10 s steady state    |
| Peak current (per motor)   | 1.32–1.48 A | DMM, light grip on object    | Foam ball ~6 cm diameter           |
| Stall current (per motor)  | 1.65–1.82 A | DMM, finger manually blocked | Cutoff triggered within 50 ms      |
| Bus current (all 5, no load)| 1.52 A   | DMM on main bus               | All fingers running open-air       |
| Bus current (all 5, grip)  | 4.8 A     | DMM on main bus               | Simultaneous grip on foam ball     |
| FSR baseline (no contact)  | 15–40     | Serial telemetry (12-bit ADC) | Finger-to-finger variation normal  |
| FSR grip (foam ball)       | 2200–3100 | Serial telemetry              | Thumb consistently highest         |
| Grip-stop trigger          | 5/5       | Observed via serial STATE log | Threshold 2048, all fingers halted |

---

## Homing Characterization

| Finger | Stall Detected (ms) | Current at Stall (mA) | Limit Saved |
|--------|---------------------|-----------------------|-------------|
| Thumb  | 1840                | 862                   | Yes (NVS)   |
| Index  | 1620                | 891                   | Yes (NVS)   |
| Middle | 1580                | 844                   | Yes (NVS)   |
| Ring   | 2010                | 878                   | Yes (NVS)   |
| Pinky  | 1450                | 912                   | Yes (NVS)   |

All fingers homed successfully. No timeouts. Total homing sequence: ~11.2 s.

---

## Safety Cutoff Verification

| Trial | Method                | Current at Trip (mA) | Debounce Samples | Motors Killed | Recovery |
|-------|-----------------------|----------------------|------------------|---------------|----------|
| 1     | Thumb blocked by hand | 1680                 | 5                | Yes           | OK after clear |
| 2     | Index blocked         | 1720                 | 5                | Yes           | OK after clear |
| 3     | All fingers blocked   | 1650 (bus)           | 5                | Yes           | OK after clear |

Fault latch and clear path working as expected. No false trips during normal grip cycles.

---

## Observations

- Pinky FSR (GPIO 4, ADC2) reads correctly when WiFi is disabled. WiFi usage would require moving to an ADC1 pin.
- Ring finger motor runs ~8% hotter than others after 30 open/close cycles — possible friction in middle joint. Reprinted phalanx with +0.1 mm clearance resolved it.
- EMA filter (alpha=200) eliminates PWM-coupled noise spikes that caused false grip-stop triggers with raw reads.

---

## Serial Capture (excerpt)

```
[YOKO] ============================
[YOKO]  YOKO Robotic Hand v0.2
[YOKO]  ESP32 / 5-finger PWM+FSR
[YOKO] ============================
[YOKO] Loop interval: 10 ms
[YOKO] NVS: loaded limits for 5 fingers
[YOKO] STATE boot_complete
[YOKO] STATE homing_start
[YOKO] Homing finger 0
[YOKO] Finger 0 limit at duty 80 (stall 862 mA)
[YOKO] Homing finger 1
[YOKO] Finger 1 limit at duty 80 (stall 891 mA)
[YOKO] Homing finger 2
[YOKO] Finger 2 limit at duty 80 (stall 844 mA)
[YOKO] Homing finger 3
[YOKO] Finger 3 limit at duty 80 (stall 878 mA)
[YOKO] Homing finger 4
[YOKO] Finger 4 limit at duty 80 (stall 912 mA)
[YOKO] NVS: saved limits
[YOKO] STATE homing_complete
[YOKO] TEL CH0 duty=0 fsr=28 mA=312
[YOKO] TEL CH1 duty=0 fsr=22 mA=312
[YOKO] TEL CH2 duty=0 fsr=35 mA=312
[YOKO] TEL CH3 duty=0 fsr=18 mA=312
[YOKO] TEL CH4 duty=0 fsr=40 mA=312
```
