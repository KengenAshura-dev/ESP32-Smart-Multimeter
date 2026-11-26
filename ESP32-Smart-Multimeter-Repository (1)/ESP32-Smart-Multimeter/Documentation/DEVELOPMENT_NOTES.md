# Development notes

## Confirmed from the earlier development conversation

- Board discussed: ESP32 Dev Module / ESP32 DevKit
- Bluetooth test device name: `ESP32_Multimeter`
- Android test application: Serial Bluetooth Terminal
- Bluetooth connectivity test: user confirmed it was working
- LCD type discussed: 16×2 I²C LCD
- LCD pins: SDA GPIO 21, SCL GPIO 22
- LCD test sketch was provided using I²C address `0x27`

## Mentioned in the broader project notes; verify before treating as final

- GPIO 34 as analog input
- 1 kΩ and 10 kΩ resistors in the measurement circuit
- Android app / Kodular integration
- Smart multimeter voltage and resistance measurement functionality

## To complete this repository

- [ ] Add the final working measurement sketch
- [ ] Confirm which measurement modes were implemented
- [ ] Add the exact resistor-divider / input-protection schematic
- [ ] Add real project photographs
- [ ] Record test readings against a trusted multimeter
- [ ] Add the Android app source or screenshots, if available
- [ ] Update README project status after verifying each feature
