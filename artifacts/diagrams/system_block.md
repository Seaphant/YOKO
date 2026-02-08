# YOKO — System Block Diagram

High-level block diagram: power path, control, drive, sensing, and safety.

---

## Mermaid

```mermaid
flowchart TB
  subgraph power["Power"]
    BAT[Battery]
    FUSE[Fuse / Current Limit]
    BAT --> FUSE
  end

  subgraph control["Control"]
    ESP[ESP32]
  end

  subgraph drive["Drive"]
    DRV[Motor Drivers x5]
    M1[Motor 1]
    M2[Motor 2]
    M3[Motor 3]
    M4[Motor 4]
    M5[Motor 5]
    FUSE --> DRV
    DRV --> M1 & M2 & M3 & M4 & M5
    ESP -->|PWM x5| DRV
  end

  subgraph sense["Sensing"]
    FSR1[FSR Thumb]
    FSR2[FSR Index]
    FSR3[FSR Middle]
    FSR4[FSR Ring]
    FSR5[FSR Pinky]
    FSR1 & FSR2 & FSR3 & FSR4 & FSR5 -->|grip stop| ESP
  end

  subgraph safety["Safety"]
    SENSE[Current Sense]
    CUTOFF[Stall / Over-current Cutoff]
    DRV --> SENSE
    SENSE --> CUTOFF
    CUTOFF -->|disable / fault| ESP
  end
```

---

## ASCII

```
                    +----------+
                    | Battery  |
                    +----+-----+
                         |
                    +----v-----+
                    | Fuse /  |
                    | Limit   |
                    +----+-----+
                         |
    +--------+      +----v-----+      +-------------+
    | ESP32  | PWM  |  Motor   |      | Motors x5   |
    |        +------> Drivers +------> (per finger) |
    |        |      +----+-----+      +-------------+
    |        |           |
    |        |      +----v-----+
    |        +<-----+ Current  |
    |   fault|      | Sense /  |
    |        |      | Cutoff   |
    |        |      +----------+
    |        |
    |   +----v----+
    +<--+ FSR x5  |  (fingertips → grip stop)
        +---------+
```

---

*Evidence artifact: system-level blocks only. No fabricated specs.*
