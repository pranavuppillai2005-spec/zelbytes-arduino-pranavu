# Irrigation State Machine

## States

### IDLE
- Default state.
- Continuously monitors soil moisture and humidity.
- Transitions to IRRIGATING when:
  - Soil moisture < threshold
  - Humidity < threshold

### IRRIGATING
- Relay ON.
- Water pump/solenoid valve active.
- Irrigation continues until:
  - Soil moisture reaches target value.

### COOLDOWN
- Relay OFF.
- Waits predefined cooldown time.
- Prevents frequent switching.

### FAULT
- Entered when DHT22 fails 3 consecutive readings.
- Relay remains OFF.
- System attempts recovery when DHT readings become valid.

---

## State Diagram

IDLE
 |
 | Soil Dry & Humidity Low
 V
IRRIGATING
 |
 | Soil Moisture Recovered
 V
COOLDOWN
 |
 | Cooldown Expired
 V
IDLE

Any State
 |
 | DHT Failure ×3
 V
FAULT
 |
 | DHT Recovered
 V
IDLE
