# Circuit Diagram & Wiring Reference

## Front-End Signal Conditioning
1. **DC Voltage Channel (`GPIO 34`):**
   - Input terminals connect across a $30\,\text{k}\Omega$ (top) and $7.5\,\text{k}\Omega$ (bottom) divider.
   - Scales $0\text{–}16.5\,\text{V}$ down to $0\text{–}3.3\,\text{V}$ for the ESP32 ADC.
   - A $3.3\,\text{V}$ Zener diode and $100\,\text{nF}$ ceramic capacitor are placed in parallel with the $7.5\,\text{k}\Omega$ resistor for over-voltage clamping and noise filtering.

2. **DC Current Channel (`GPIO 35`):**
   - ACS712-05B powered from the $5\,\text{V}$ (`VIN`) rail.
   - Because the ACS712 outputs $2.5\,\text{V}$ at $0\,\text{A}$ and swings up to $3.425\,\text{V}$ at $+5\,\text{A}$, a $10\,\text{k}\Omega / 20\,\text{k}\Omega$ divider drops the sensor output by $2/3$ so it stays safely below $3.3\,\text{V}$.

3. **Resistance Channel (`GPIO 32`):**
   - $3.3\,\text{V}$ regulated rail feeds a $10\,\text{k}\Omega$ ($1\%$ tolerance) reference resistor in series with the unknown resistor $R_x$ to ground.
   - Midpoint connects directly to `GPIO 32`.

4. **Display (`GPIO 21` / `GPIO 22`):**
   - 16x2 LCD I2C backpack powered from `VIN` ($5\,\text{V}$) for proper screen contrast; SDA/SCL lines use the backpack's onboard pull-ups.

## Safety Limits
- Do not apply AC mains voltage or DC inputs exceeding $16.5\,\text{V}$ to the voltage probes.
- Always connect the ground probe first before probing live nodes.
