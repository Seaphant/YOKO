# YOKO — Finger Linkage / Joint Concept

Conceptual layout of one finger: multi-joint, linkage, and motor attachment. Used for tolerance and binding iteration.

---

## ASCII — Single Finger (Side View)

```
                    [Motor]
                        |
                        | (shaft / linkage)
                        v
    +-------+     +-------+     +-------+
    | Phalanx|-----| Joint |-----| Phalanx|  ... (multi-joint)
    |  (prox) |     |       |     | (dist) |
    +-------+     +-------+     +-------+
                        |
                   [FSR at tip]
```

---

## ASCII — Joint Detail (Tolerance / Binding Focus)

```
         linkage in
            |
    +-------v-------+
    |   Bearing /   |   ← clearance [TBD]; tune to reduce binding
    |   Pin / Boss  |   ← backlash reduced by iteration
    +-------^-------+
            |
         linkage out
```

---

## Mermaid — Finger Channels (5 Fingers)

```mermaid
flowchart LR
  subgraph fingers
    T[Thumb]
    I[Index]
    M[Middle]
    R[Ring]
    P[Pinky]
  end
  subgraph motors
    MT[M1]
    MI[M2]
    MM[M3]
    MR[M4]
    MP[M5]
  end
  T --> MT
  I --> MI
  M --> MM
  R --> MR
  P --> MP
```

---

*Evidence: mechanical structure concept. Swappable parts allow per-finger iteration. No fabricated dimensions.*
