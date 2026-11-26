#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

bool wasConnected = false;

void setup() {
  Serial.begin(115200);

  if (!SerialBT.begin("ESP32_Multimeter")) {
    Serial.println("Bluetooth initialization failed!");
    while (true) {
      delay(1000);
    }
  }

  Serial.println("Bluetooth started.");
  Serial.println("Pair/connect to: ESP32_Multimeter");
}

void loop() {
  bool connected = SerialBT.hasClient();

  if (connected && !wasConnected) {
    wasConnected = true;
    Serial.println("Bluetooth connected!");
  } else if (!connected && wasConnected) {
    wasConnected = false;
    Serial.println("Bluetooth disconnected!");
  }

  if (connected) {
    SerialBT.println("ESP32 Bluetooth test: connection is working.");
    delay(1000);
  } else {
    delay(100);
  }

  // Optional: receive text sent from the phone and echo it.
  while (SerialBT.available()) {
    String message = SerialBT.readStringUntil('\n');
    message.trim();

    if (message.length() > 0) {
      Serial.print("Received from phone: ");
      Serial.println(message);
      SerialBT.print("ESP32 received: ");
      SerialBT.println(message);
    }
  }
}
