# ESP32 Smart Multimeter

An ESP32-based electronics project exploring analog measurement, LCD interfacing, and wireless monitoring over Bluetooth Classic.

> **Project status:** This repository currently contains the ESP32 Bluetooth connectivity test and 16×2 I²C LCD test sketches discussed during development. The complete voltage/resistance measurement firmware and final circuit have not been recovered yet, so this README does not claim that the complete multimeter is finished.

## Features covered in the available code

- ESP32 Bluetooth Classic serial device named `ESP32_Multimeter`
- Connection/disconnection status on the Arduino Serial Monitor
- Test message transmission to an Android Bluetooth serial terminal
- 16×2 I²C LCD initialization and text display
- I²C pins: SDA = GPIO 21, SCL = GPIO 22

## Hardware

| Component | Purpose |
|---|---|
| ESP32 DevKit V1 | Main controller |
| 16×2 LCD with I²C backpack | Local display |
| Android phone | Bluetooth testing |
| Resistors / measurement circuit | Intended analog measurement stage |

The earlier project notes also mention GPIO 34 as an ADC input and 1 kΩ / 10 kΩ resistors. Confirm the actual circuit and resistor arrangement before using them in a measurement implementation.

## Pin connections

### I²C LCD

| LCD module | ESP32 |
|---|---|
| SDA | GPIO 21 |
| SCL | GPIO 22 |
| GND | GND |
| VCC | Use the voltage supported by your LCD backpack and ESP32 logic-level requirements |

The sketches use I²C address `0x27`. If the display does not respond, run an I²C scanner and verify the address. Some modules use `0x3F`.

### Analog input (planned)

| Signal | ESP32 |
|---|---|
| Analog measurement output | GPIO 34 |

**Safety:** Do not connect mains voltage or an unknown/high voltage directly to the ESP32. GPIOs are not 5 V tolerant. Use a properly designed, rated input-conditioning/protection circuit and verify its output stays within the ESP32 ADC input limits. This repository does not yet provide a validated measurement front end.

## Software requirements

- Arduino IDE
- ESP32 board support package installed
- Board selected: **ESP32 Dev Module**
- `LiquidCrystal_I2C` library for the LCD sketch
- `BluetoothSerial` is included with the Arduino-ESP32 core (Bluetooth Classic support depends on the ESP32 chip variant; ESP32-S2 does not support Bluetooth, and ESP32-C3/S3 support differs from the original ESP32)

## Repository layout

```text
ESP32-Smart-Multimeter/
├── README.md
├── LICENSE
├── .gitignore
├── Code/
│   ├── Bluetooth_Test/
│   │   └── Bluetooth_Test.ino
│   └── LCD_Test/
│       └── LCD_Test.ino
├── Circuit_Diagram/
│   └── README.md
├── Documentation/
│   └── DEVELOPMENT_NOTES.md
└── Images/
    └── README.md
```

## Run the tests

### 1. Bluetooth test

1. Open `Code/Bluetooth_Test/Bluetooth_Test.ino` in Arduino IDE.
2. Select **ESP32 Dev Module** and the correct COM/USB port.
3. Upload the sketch.
4. Open Serial Monitor at **115200 baud**.
5. On Android, open **Serial Bluetooth Terminal** (by Kai Morich), select `ESP32_Multimeter`, and connect.
6. The Serial Monitor should report `Bluetooth connected!`; the phone terminal should receive a test message every second.
7. Disconnect from the app to check for `Bluetooth disconnected!`.

### 2. LCD test

1. Install a compatible `LiquidCrystal_I2C` library from Arduino IDE Library Manager.
2. Open `Code/LCD_Test/LCD_Test.ino`.
3. Wire SDA to GPIO 21 and SCL to GPIO 22.
4. Upload the sketch.
5. The LCD should show `LCD Test: OK!` and `ESP32 is Online`.

If the backlight turns on but no text appears, adjust the contrast potentiometer on the I²C backpack and verify the I²C address and wiring.

## Screenshots and photographs

Add your own project photos to `Images/`, then link them here. Suggested photos:
- Complete breadboard/circuit
- ESP32 and LCD wiring close-up
- LCD showing live readings (only after measurement firmware is implemented)
- Android Bluetooth terminal connected to the ESP32

## Future work

- Recover and add the final analog measurement firmware
- Validate voltage/resistance calculations against a calibrated multimeter
- Display measured values on the LCD
- Send structured measurement data to an Android app
- Add input protection, calibration, and measurement-range handling
- Document the final circuit diagram and test results

## Author

**Manish Jaywant Patil**

Electronics & Telecommunication Engineering

---

If you use or extend this project, please verify the circuit and test it with safe, current-limited low-voltage sources before making measurements.
