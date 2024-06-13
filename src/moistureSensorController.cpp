#include "moistureSensorController.h"

MoistureSensorController::MoistureSensorController()
{

}

bool MoistureSensorController::isMoist()
{
    currentMoisture = analogRead(moistureSensorPin);
    if (map(currentMoisture, wet, dry, 100, 0) < 50)
    {
        return false;
    }
    return true;
}