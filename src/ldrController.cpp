#include "ldrController.h"

LdrController::LdrController()
{

}

void LdrController::setupLdr()
{
    pinMode(ldrPin, INPUT);
    initialLight = analogRead(ldrPin);
}

bool LdrController::isLightTooLow()
{
  currentLight = analogRead(ldrPin);
  if(initialLight - currentLight >= 200) {
  return true;
}
return false;
}