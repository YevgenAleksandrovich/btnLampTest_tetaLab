# Project: LED Control with ESP32

## Description

This project demonstrates how to control an LED using a button with debounce and PWM on an ESP32 WROOM microcontroller.

## Features

- **Button Control**: Toggles the LED on and off.
- **PWM Control**: Adjusts the brightness of the LED to create a breathing effect.

## Files

- `btnLamp.cpp`: Main source file containing the code for controlling the LED.

## Setup Instructions

1. **Install Arduino IDE** or **Visual Studio Code**.
2. **Install ESP32 Board Support**:
   - In Arduino IDE, go to **File > Preferences** and add `https://dl.espressif.com/dl/package_esp32_index.json` in the "Additional Boards Manager URLs".
   - Then go to **Tools > Board > Boards Manager**, search for `esp32` and install it.
3. **Open the Project**:
   - In Arduino IDE, open `btnLamp.cpp`.
   - In Visual Studio Code, open the project folder and use the Arduino extension to load the code.
4. **Select Board and Port**:
   - In Arduino IDE, go to **Tools > Board** and select `ESP32 Dev Module`.
   - Go to **Tools > Port** and select the appropriate port.
5. **Upload the Code**: Click **Upload** in Arduino IDE or use the build and upload commands in Visual Studio Code.

## Wiring

- Connect the button to GPIO 0 (P2).
- Connect the LED to GPIO 2 with appropriate current limiting resistor.

## License

This project is licensed under the MIT License.
