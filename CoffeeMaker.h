//
// Created by Keaton Burleson on 11/29/21.
//

#ifndef HONORSPROJECT_COFFEEMAKER_H
#define HONORSPROJECT_COFFEEMAKER_H


#include "components/type/Component.h"
#include "components/Heater.h"
#include "components/Boiler.h"
#include "components/Tank.h"
#include "components/Sensor.h"
#include "components/Indicator.h"
#include "helpers/ProgressBar.h"
#include "status/IndicatorStatus.h"
#include "types/BrewConfig.h"
#include "components/FilterBasket.h"
#include "logging/ContextLogger.h"


class CoffeeMaker: public ContextLogger {
public:
    explicit CoffeeMaker(BrewConfig config);
    void brew();

private:
    TanksStatus checkTanks();

    void brewTick();

    void setupBoilerListener(double initialTemperature, bool boilerFilled);
    void setupFilterListeners(BrewStrength strength);
    void setupCarafeListener(bool carafeAvailable);
    void setupIndicators();

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

    // Coffee Filter Basket
    FilterBasket filterBasket = FilterBasket("Filter Basket");
    CoffeeFilter mainFilter = CoffeeFilter("Main Filter");
    CoffeeGrinds currentGrinds = CoffeeGrinds();
};

#endif //HONORSPROJECT_COFFEEMAKER_H
