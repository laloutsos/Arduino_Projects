# Arduino LCD Robot with DHT11 Sensor and Buttons

## Overview
This project is a simple Arduino-based system that uses an LCD display, a DHT11 temperature sensor, and two buttons to show different states and environmental information.

## Features
- Displays a default "Robot" message on startup
- Button 1 shows a happy face and message
- Button 2 shows an angry face and message
- When no button is pressed, it reads temperature from the DHT11 sensor
- Displays temperature and a simple mood based on the reading:
  - Cold temperature shows "Cold" with an angry face
  - Normal temperature shows "Nice" with a happy face

## Hardware Requirements
- Arduino board
- 16x2 LCD display (parallel interface)
- DHT11 temperature and humidity sensor
- 2 push buttons
- Potentiometer (for LCD contrast)
- Resistors and jumper wires

## Libraries Used
- LiquidCrystal
- dht_nonblocking

## Pin Configuration
- LCD pins: 7, 8, 9, 10, 11, 12
- DHT11 sensor: pin 4
- Button 1: pin 5
- Button 2: pin 6

## How It Works
The system continuously checks the state of the two buttons. If a button is pressed, it shows a corresponding emotion on the LCD. If no button is pressed, it reads the temperature from the DHT11 sensor and displays it along with a simple condition-based message.

## Notes
- This project is under development, so I will keep updating it.

