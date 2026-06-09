
# Sensor Calibration and Data Logger

## Objective

Calibrate and log data from:

- LDR (Light Dependent Resistor)
- DHT22 / AM2301
- HC-SR04 Ultrasonic Sensor
- Soil Moisture Analog Sensor

The system outputs sensor readings in CSV format through Serial Monitor.

---

## Hardware Used

| Component | Quantity |
|------------|------------|
| Arduino UNO | 1 |
| LDR | 1 |
| 10kΩ Resistor | 1 |
| DHT22 Sensor | 1 |
| HC-SR04 | 1 |
| Soil Moisture Sensor | 1 |

---

## Pin Connections

### LDR

LDR Voltage Divider Output → A0

### DHT22

DATA → D2

### HC-SR04

TRIG → D9

ECHO → D10

### Soil Moisture

AO → A1

---

## Calibration Constants

### Soil Sensor

Dry Soil = 850

Wet Soil = 300

### LDR

Bright = < 300

Normal = 300–700

Dark = > 700

---

## Sensor Placement

### HC-SR04

Mount sensor:

- Height: 20–30 cm above target surface
- Keep sensor level
- Avoid angled surfaces

### Soil Moisture Sensor

Insert probe:

- 4–6 cm depth
- Fully cover sensing region
- Avoid stones near probe

### DHT22

- Keep away from direct sunlight
- Install 1 m above ground

### LDR

- Place facing ambient light source
- Avoid shadows from nearby objects

---

## Serial Output Format

millis,temp,humidity,distance_cm,soil_raw

Example:

1200,28.3,65.1,42.8,512
