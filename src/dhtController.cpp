#include "dhtController.h"

DhtController::DhtController() : dht(pin, type)
{

}

void DhtController::setupDht()
{
    dht.begin();
}

bool DhtController::isDhtReady() {
  humidity = dht.readHumidity();
  temperature = dht.readTemperature();

  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return false;
  }
  return true;
}

int DhtController::getHumidity()
{
    return humidity;
}

int DhtController::getTemperature()
{
    return temperature;
}