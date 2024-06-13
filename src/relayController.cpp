#include "relayController.h"

RelayController::RelayController()
{

}

void RelayController::setupRelay()
{
    pinMode(relayPin, OUTPUT);
}

void RelayController::turnRelayOn()
{
    digitalWrite(relayPin, HIGH);
    relayOn = true;
}

void RelayController::turnRelayOff()
{
    digitalWrite(relayPin, LOW);
    relayOn = false;
}

bool RelayController::isRelayOn()
{
    return relayOn;
}