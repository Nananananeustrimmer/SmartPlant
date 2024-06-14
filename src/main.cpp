#include "networking.h"
#include "ldrController.h"
#include "dhtController.h"
#include "moistureSensorController.h"
#include "relayController.h"
#include "rfController.h"
#include <Arduino.h>

DhtController dhtController;
LdrController ldrController;
Networking networking;
MoistureSensorController moistureSensorController;
RelayController relayController;
RfController rfController;

void setup() {
  Serial.begin(9600);
  networking.setupWifi();
  ldrController.setupLdr();
  dhtController.setupDht();
  relayController.setupRelay();
  rfController.setupRf();
}

void loop() {
  if (dhtController.isDhtReady()) {
    networking.addData("humidity", dhtController.getHumidity());
    networking.addData("temperature", dhtController.getTemperature());
  }
  networking.updateData();

  if (moistureSensorController.isMoist() && relayController.isRelayOn())
  {
    relayController.turnRelayOff();
  } else if (!moistureSensorController.isMoist() && !relayController.isRelayOn())
  {
    relayController.turnRelayOn();
  }

  if(ldrController.isLightTooLow() && !rfController.isKakuOn())
  {
    rfController.turnKaKuOn();
  } else if (!ldrController.isLightTooLow() && rfController.isKakuOn())
  {
    rfController.turnKaKuOff();
  }
  delay(5000);
}
