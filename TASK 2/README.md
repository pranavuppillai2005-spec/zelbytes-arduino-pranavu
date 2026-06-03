
# Zelbytes Arduino Setup

## Objective

To set up an Arduino firmware development workspace, configure version control using GitHub, and verify successful program upload and serial communication.

## Repository Structure

```text
src/
├── Blink/
│   └── Blink.ino
└── SerialHello/
    └── SerialHello.ino

docs/
└── HARDWARE.md

README.md
```

## Hardware Information

* Board: Arduino Uno R3
* Microcontroller: ATmega328P
* Port: /dev/cu.usbserial-110

## Implemented Sketches

### Blink

A basic Arduino program that blinks the built-in LED every second to verify successful board programming.

### SerialHello

A serial communication test program that sends the message "Hello from Arduino!" to the Serial Monitor every second.

## Development Environment

* Arduino IDE 2.x
* Arduino AVR Boards Package
* Git & GitHub for Version Control

## Verification

* Successful sketch upload confirmed.
* Built-in LED blinking verified.
* Serial Monitor output verified at 9600 baud.

### Sample Output

Hello from Arduino!
Hello from Arduino!
Hello from Arduino!

## Author

Pranav P Pillai
