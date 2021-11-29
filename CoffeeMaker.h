//
// Created by Keaton Burleson on 11/29/21.
//

#ifndef HONORSPROJECT_COFFEEMAKER_H
#define HONORSPROJECT_COFFEEMAKER_H

#include <iostream>

#include "components/type/Component.h"
#include "components/Heater.h"
#include "components/Boiler.h"
#include "components/Tank.h"
#include "components/Sensor.h"
#include "components/Indicator.h"
#include "helpers/ProgressBar.h"
#include "status/IndicatorStatus.h"

using std::cout;

class CoffeeMaker {
public:
    CoffeeMaker();

    void fillWaterTank();

    void emptyCarafe();

    void brew();

private:
    TanksStatus checkTanks();

    void brewTick();

    void startBoiler();

    static void printMessage(const string &message, bool appendNewline = false);

protected:
    // Plate Heater
    Heater plateHeater = Heater("Plate Heater");
    Indicator plateHeaterIndicator = Indicator("Plate Heater");

    // Boiler
    Boiler boiler = Boiler("Main Boiler");

    // Carafe, Carafe Detection
    Tank carafe = Tank("Carafe");
    Sensor carafeSensor = Sensor("Carafe");

    // Brew Indicator
    Indicator brewIndicator = Indicator("Brew");
};

#endif //HONORSPROJECT_COFFEEMAKER_H
