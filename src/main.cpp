#include "DHT.h"
#include "networking.h"
#include <Arduino.h>

#define DHTPIN 32

#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
Networking networking;

void setup() {
  Serial.begin(9600);
  networking.setupWifi();
  dht.begin();
}

bool isDhtReady(int humidity, int temperature) {
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return false;
  }
  return true;
}

void loop() {
  
  int humidity = dht.readHumidity();
  int temperature = dht.readTemperature();

  if (isDhtReady(humidity, temperature)) {
    networking.addData("humidity", humidity);
    networking.addData("temperature", temperature);
  }

  networking.updateData();
  Serial.println("Wait 10s");
  delay(10000);
}
