#ifndef MOISTURE_SENSOR_CONTROLLER_H
#define MOISTURE_SENSOR_CONTROLLER_H

#include <Arduino.h>

class MoistureSensorController
{
public:
    MoistureSensorController();
    bool isMoist();
private:
const int moistureSensorPin = 36;
const int dry = 3100;
const int wet = 1100;
int currentMoisture = 0;
};

#endif // MOISTURE_SENSOR_CONTROLLER_H