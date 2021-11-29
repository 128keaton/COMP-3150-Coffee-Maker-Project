//
// Created by Keaton Burleson on 11/28/21.
//

#ifndef HONORSPROJECT_PLATESENSOR_H
#define HONORSPROJECT_PLATESENSOR_H


#include "LogicalSensor.h"
#include "../heaters/BaseHeater.h"
#include "../indicators/PlateIndicator.h"
#include "../containers/Carafe.h"

class PlateSensor: public LogicalSensor {
public:
    void removeCarafe();
    void replaceCarafe(Carafe carafe);
    void carafeUpdated(Carafe carafe);
    bool isTripped() override;

private:
    bool carafeAvailable = false;
    BaseHeater heater = BaseHeater("Plate");
    PlateIndicator indicator = PlateIndicator();
};


#endif //HONORSPROJECT_PLATESENSOR_H
