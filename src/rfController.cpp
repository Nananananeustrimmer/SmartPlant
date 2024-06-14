#include "rfController.h"
#include "switchKaKu.h"

RfController::RfController()
{

}

void RfController::setupRf()
{
    turnKaKuOff();
}

void RfController::turnKaKuOn()
{
    switchKaku(rfPin, kaKuId, 1, 1, true, 3);
    kaKuOn = true;
}

void RfController::turnKaKuOff()
{
    switchKaku(rfPin, kaKuId, 1, 1, false, 3);
    kaKuOn = false;
}

bool RfController::isKakuOn()
{
    return kaKuOn;
}