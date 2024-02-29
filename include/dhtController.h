#ifndef DHT_CONTROLLER_H
#define DHT_CONTROLLER_H

#include "DHT.h"
#include <Arduino.h>

class DhtController
{
public:
    DhtController();
    void setupDht();
    bool isDhtReady();
    int getHumidity();
    int getTemperature();

private:
const int pin = 32;
const byte type = DHT11;
int humidity;
int temperature;

DHT dht;
};

#endif // DHT_CONTROLLER_H