#include "networking.h"
#include "ldrController.h"
#include "dhtController.h"
#include "moistureSensorController.h"
#include <Arduino.h>

DhtController dhtController;
LdrController ldrController;
Networking networking;
MoistureSensorController moistureSensorController;

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
  Serial.println("is low:");
  Serial.println(ldrController.isLightTooLow());
  Serial.println("is moist:");
  Serial.println(moistureSensorController.isMoist());
  delay(5000);
}
