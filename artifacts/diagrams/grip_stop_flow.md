# YOKO — FSR Grip-Stop Closed-Loop Flow

Closed-loop behavior: FSR fingertip sensing triggers grip stop when contact/threshold is reached.

---

## Mermaid — Data Flow

```mermaid
flowchart LR
  CMD[Close Command] --> MC[Motor Control]
  MC --> PWM[PWM to Drivers]
  PWM --> M[Motors]
  M --> FSR[FSR Fingertips]
  FSR --> READ[Read FSR]
  READ --> THRESH{Above threshold?}
  THRESH -->|No| MC
  THRESH -->|Yes| STOP[Stop / Hold]
  STOP --> MC
```

---

## ASCII — Sequence

```
  User: "Close hand"
       |
       v
  Motor control: drive fingers closed
       |
       v
  FSR read (per finger or combined)
       |
       v
  Threshold reached? ----No----> keep driving (rate limit)
       |
      Yes
       |
       v
  Stop PWM / hold position
       |
       v
  (Optional: slight release or maintain grip)
```

---

## Notes

- Threshold 512 (0–1023) in firmware config; FSR used for grip-stop behavior only (confirmed).
- Optional expansion: per-finger pressure, slip detection.
