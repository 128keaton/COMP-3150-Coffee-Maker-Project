//
// Created by Keaton Burleson on 11/28/21.
//

#ifndef HONORSPROJECT_COFFEEMAKER_H
#define HONORSPROJECT_COFFEEMAKER_H


#include "enums/BrewStatus.h"
#include "components/containers/Boiler.h"
#include "components/sensors/PlateSensor.h"
#include "consumables/CoffeeFilter.h"

class CoffeeMaker {
public:
    CoffeeMaker() {}

    BrewStatus getStatus();
    bool isPaused();
    bool isFinished();
    bool isBrewing();
    bool isWaiting();

    void setBrewing();
    void setInterruptAt(double haltAt);

private:
    double progress = 0.0;
    double progressHaltAt = -1.0;
    BrewStatus status = WAITING;
    CoffeeFilter coffeeFilter = CoffeeFilter();
    Boiler boiler = Boiler(1, "Liter");
    Carafe carafe = Carafe();
    PlateSensor plate = PlateSensor();
    void setFinished();
    void updateProgress(double progress);
};


#endif //HONORSPROJECT_COFFEEMAKER_H
