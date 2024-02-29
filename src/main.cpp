#include "networking.h"
#include "dhtController.h"
#include <Arduino.h>

DhtController dhtController;
Networking networking;

void setup() {
  Serial.begin(9600);
  networking.setupWifi();
  dhtController.setupDht();
}

void loop() {
  if (dhtController.isDhtReady()) {
    networking.addData("humidity", dhtController.getHumidity());
    networking.addData("temperature", dhtController.getTemperature());
  }
  networking.updateData();
  Serial.println("Wait 10s");
  delay(10000);
}
