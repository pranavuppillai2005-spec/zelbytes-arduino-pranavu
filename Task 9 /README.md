# Grow Bench Firmware v1.0

## Overview

This project implements an automatic irrigation system using Arduino UNO. The system monitors soil moisture and controls a relay-operated solenoid valve. It supports both automatic operation and manual override.

## Features

* Automatic irrigation based on soil moisture threshold
* Manual override button
* Serial command interface
* Relay-controlled valve
* DHT11 temperature and humidity monitoring
* LDR light sensing

## Serial Commands

### STATUS

Displays current system information.

```text
STATUS
```

### FORCE_ON

Forces irrigation ON.

```text
FORCE_ON
```

### FORCE_OFF

Forces irrigation OFF.

```text
FORCE_OFF
```

## Hardware

* Arduino UNO
* DHT11 Sensor
* Soil Moisture Sensor
* LDR Sensor
* 5V Relay Module
* 12V Solenoid Valve
* Push Button
* Breadboard
* Jumper Wires

## Wiring

| Component     | Arduino Pin |
| ------------- | ----------- |
| DHT11 DATA    | D2          |
| Soil Moisture | A0          |
| LDR           | A1          |
| Relay IN      | D8          |
| Manual Button | D7          |

## Build Instructions

1. Install Arduino IDE.
2. Install DHT Sensor Library.
3. Open `grow_bench_v1.ino`.
4. Select Arduino UNO board.
5. Upload firmware.

## Repository Structure

```text
README.md

docs/
├── DEMO_CHECKLIST.md
└── FIRMWARE_V1_REPORT.md

src/
└── firmware_v1/
    └── grow_bench_v1.ino


```

## Version

Firmware Version: v1.0-capstone
