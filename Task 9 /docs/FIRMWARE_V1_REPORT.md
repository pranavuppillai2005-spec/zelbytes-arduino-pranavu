# Firmware v1.0 Report

## Project Title

Smart Grow Bench Irrigation System – Firmware v1.0

## Objective

Develop firmware capable of automatic irrigation based on soil moisture thresholds while supporting manual override and serial command control.

---

## System Description

The firmware continuously monitors environmental conditions and controls irrigation automatically.

The system reads:

* Soil Moisture Sensor
* DHT11 Temperature Sensor
* DHT11 Humidity Sensor
* LDR Light Sensor

The relay controls a 12V solenoid valve used for irrigation.

---

## Features Implemented

### Automatic Irrigation

The firmware compares soil moisture against a predefined threshold.

If moisture is below threshold:

* Relay ON
* Valve Open

If moisture is above threshold:

* Relay OFF
* Valve Closed

---

### Manual Override

A push button is used for manual override.

The operator can temporarily control irrigation independent of automatic mode.

---

### Serial Commands

Three commands are supported:

| Command   | Function              |
| --------- | --------------------- |
| STATUS    | Display system status |
| FORCE_ON  | Force irrigation ON   |
| FORCE_OFF | Force irrigation OFF  |

---

## Testing

### Auto Mode Test

Dry soil condition successfully activated irrigation.

Result: PASS

### Wet Soil Test

Wet soil condition successfully stopped irrigation.

Result: PASS

### Manual Override Test

Manual button successfully toggled control.

Result: PASS

### Serial Command Test

All commands executed correctly.

Result: PASS

---

## Results

| Test              | Result |
| ----------------- | ------ |
| Auto Irrigation   | PASS   |
| Manual Override   | PASS   |
| STATUS Command    | PASS   |
| FORCE_ON Command  | PASS   |
| FORCE_OFF Command | PASS   |
| Relay Control     | PASS   |

---

## Known Limitations

* Soil moisture sensor may corrode over time.
* DHT11 has limited accuracy.
* Single-zone irrigation only.
* No cloud connectivity.

---

## Git Tag

```text
v1.0-capstone
```

---

## Conclusion

Firmware v1.0 successfully meets all capstone requirements. Automatic irrigation, manual override, and serial command functionality were implemented and verified through testing.
