#ifndef LDR_CONTROLLER_H
#define LDR_CONTROLLER_H

#include <Arduino.h>

class LdrController
{
public:
    LdrController();
    void setupLdr();
    bool isLightTooLow();
private:
const int ldrPin = 39;
int initialLight = 0;
int currentLight = 0;
};

#endif // LDR_CONTROLLER_H