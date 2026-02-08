# YOKO — PWM Control (Concept)

Per-finger PWM to motor drivers; rate limiting applied to avoid sudden load spikes.

---

## ASCII — PWM Concept (One Channel)

```
  Duty cycle 0% -------- 100%
       |                    |
  Full reverse    Neutral   Full forward
       |            |            |
  <----+------------+------------+---->
       ^            ^            ^
     (direction + magnitude; driver-dependent)
```

---

## Mermaid — Multi-Channel Assignment

```mermaid
flowchart LR
  ESP[ESP32]
  ESP --> P1[PWM Ch 1]
  ESP --> P2[PWM Ch 2]
  ESP --> P3[PWM Ch 3]
  ESP --> P4[PWM Ch 4]
  ESP --> P5[PWM Ch 5]
  P1 --> D1[Driver 1 - Thumb]
  P2 --> D2[Driver 2 - Index]
  P3 --> D3[Driver 3 - Middle]
  P4 --> D4[Driver 4 - Ring]
  P5 --> D5[Driver 5 - Pinky]
```

---

## Rate Limiting (Concept)

```
  Command: step target duty
       |
       v
  Current duty +/- max delta per cycle
       |
       v
  Output PWM (smoother motion; less peak current)
```

---

*Evidence: PWM and channel layout. 1 kHz, 8-bit in config.h; see firmware.*
