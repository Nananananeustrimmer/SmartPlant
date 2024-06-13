#include "networking.h"
#include "ldrController.h"
#include "dhtController.h"
#include <Arduino.h>

DhtController dhtController;
LdrController ldrController;
Networking networking;

void setup() {
  Serial.begin(9600);
  networking.setupWifi();
  ldrController.setupLdr();
  dhtController.setupDht();
}

void loop() {
  if (dhtController.isDhtReady()) {
    networking.addData("humidity", dhtController.getHumidity());
    networking.addData("temperature", dhtController.getTemperature());
  }
  networking.updateData();
  Serial.println(ldrController.isLightTooLow());
  delay(5000);
}
