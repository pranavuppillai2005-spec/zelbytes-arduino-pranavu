# Hardware Used

## Components

* Arduino UNO
* Push Button
* LED
* 220Ω Resistor
* Relay Module (5V)
* Solenoid Valve
* External Power Supply
* Breadboard
* Jumper Wires

## Button LED Connections

Button:

* One terminal → D2
* Other terminal → GND

LED:

* Anode (+) → D13
* Cathode (-) → 220Ω resistor → GND

## Relay Valve Connections

Relay Module:

* IN → D7
* VCC → 5V
* GND → GND

Solenoid Valve:

* Powered through relay contacts
* Uses external power supply
* Never connected directly to Arduino GPIO

