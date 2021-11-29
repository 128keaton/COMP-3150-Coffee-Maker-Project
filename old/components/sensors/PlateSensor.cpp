//
// Created by Keaton Burleson on 11/28/21.
//

#include "PlateSensor.h"

bool PlateSensor::isTripped() {
    return this->carafeAvailable;
}

void PlateSensor::removeCarafe() {
    this->carafeAvailable = false;
    this->heater.setHeating(false);
    this->indicator.setOff();
}

void PlateSensor::replaceCarafe(Carafe carafe) {
    this->carafeAvailable = true;

    this->heater.setHeating(!carafe.isEmpty());

    if (this->heater.isHeating()) {
        this->indicator.setOn();
    } else {
        this->indicator.setOff();
    }
}

void PlateSensor::carafeUpdated(Carafe carafe) {
    if (!carafe.isEmpty() && !this->heater.isHeating()) {
        this->heater.setHeating(true);
        this->indicator.setOn();
    }
}
