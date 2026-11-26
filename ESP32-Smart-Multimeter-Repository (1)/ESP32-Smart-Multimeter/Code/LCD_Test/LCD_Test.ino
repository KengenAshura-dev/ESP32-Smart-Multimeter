#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Change 0x27 to 0x3F if your I2C scanner detects that address.
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(115200);

  // ESP32 default I2C pins used in this project:
  // SDA = GPIO 21, SCL = GPIO 22
  Wire.begin(21, 22);

  lcd.init();
  lcd.backlight();
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("LCD Test: OK!");

  lcd.setCursor(0, 1);
  lcd.print("ESP32 is Online");

  Serial.println("LCD test initialized.");
  Serial.println("If the LCD is blank, check power, wiring, contrast, and I2C address.");
}

void loop() {
  // Static display test; no repeated action is required.
}
