# Firmware Architecture

## Modules

| Module | Role |
|--------|------|
| motor_control | PWM → drivers; per-finger channels; rate limiting |
| calibration | Homing; travel limits; NVS save |
| safety | Over-current detection; stall cutoff (~1.5 A) |
| sensors | FSR fingertip → grip-stop |
| logging | Serial debug; test markers |

## Data Flow

```
Command/Homing → calibration → motor_control
FSR → sensors → motor_control
motor_control → safety → motor_control
motor_control → PWM, logging
```

See [firmware/docs/modules.md](../firmware/docs/modules.md) for Mermaid diagram.
