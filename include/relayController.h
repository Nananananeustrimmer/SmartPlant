#ifndef RELAY_CONTROLLER_H
#define RELAY_CONTROLLER_H

#include <Arduino.h>

class RelayController
{
public:
    RelayController();
    void setupRelay();
    void turnRelayOn();
    void turnRelayOff();
    bool isRelayOn();
private:
const int relayPin = 33;
bool relayOn = false;
};

#endif // RELAY_CONTROLLER_H