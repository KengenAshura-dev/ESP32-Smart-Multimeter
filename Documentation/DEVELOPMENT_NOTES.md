# Development & Bench Testing Notes

## Hardware Bring-Up Log
- **I2C LCD Check:** Confirmed backpack I2C address is `0x27` using an I2C scanner sketch. Contrast potentiometer on the back of the PCF8574 board had to be turned roughly halfway before characters became visible.
- **Bluetooth SPP Check:** Verified `BluetoothSerial` works reliably alongside `GPIO 34/35/32` (`ADC1`). Avoided `ADC2` pins (`GPIO 0, 2, 4, 12-15, 25-27`) because Wi-Fi/BT radio activity interferes with `ADC2` conversions.

## ADC Calibration Findings
- The ESP32 12-bit ADC (`0–4095`) shows noticeable non-linearity below $0.15\,\text{V}$ and above $3.0\,\text{V}$.
- Averaging 64 samples per measurement cycle plus applying a two-point linear correction factor brought DC voltage readings within $\pm 0.04\,\text{V}$ of a Fluke 101 reference meter across the $1.5\,\text{V}\text{–}15\,\text{V}$ range.
- Added a $100\,\text{nF}$ decoupling capacitor close to `GPIO 34` to cut down switching noise from the USB-to-UART regulator.

