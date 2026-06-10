# README.md

# Smart Irrigation System Using Arduino UNO

## Overview

This project implements an automatic irrigation system using:

* Arduino UNO
* Capacitive Soil Moisture Sensor v1.2
* DHT22 Humidity Sensor
* 5V Relay Module
* 12V DC Solenoid Valve
* Status LED

The system uses a state machine with four states:

1. IDLE
2. IRRIGATING
3. COOLDOWN
4. FAULT

The relay controls the solenoid valve based on soil moisture and humidity readings.

## Features

* Soil moisture displayed in percentage
* Automatic irrigation
* Relay-controlled solenoid valve
* DHT22 fault detection
* Cooldown period after irrigation
* LED status indication

## Hardware

* Arduino UNO
* Capacitive Soil Moisture Sensor v1.2
* DHT22
* 5V Relay Module
* 12V Solenoid Valve
* LED
* 1kΩ Resistor
* 12V Power Supply

## Author

Pranavu P Pillai
