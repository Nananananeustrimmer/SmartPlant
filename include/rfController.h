#ifndef RF_CONTROLLER_H
#define RF_CONTROLLER_H

#include <Arduino.h>

class RfController
{
public:
    RfController();
    void setupRf();
    void turnKaKuOn();
    void turnKaKuOff();
    bool isKakuOn();
private:
const int rfPin = 25;
const unsigned long kaKuId = 6969;
bool kaKuOn = false;
};

#endif // RF_CONTROLLER_H