//
// Created by Keaton Burleson on 11/29/21.
//

#include "CoffeeMaker.h"

/// MARK - Public

CoffeeMaker::CoffeeMaker(BrewConfig config) : ContextLogger("Coffee Maker") {
    this->setupIndicators();
    this->setupFilterListeners(config.strength);
    this->setupCarafeListener(config.carafeAvailable);
    this->setupBoilerListener((config.boilerHot ? 100.0 : 0.0), config.boilerFilled);

    if (config.carafeEmpty) {
        this->carafe.empty();
    }

    if (config.boilerFilled) {
        this->boiler.fillNow();
    } else {
        this->boiler.empty();
    }
}

/**
 * Kicks off the brew cycle
 */
void CoffeeMaker::brew() {
    if (!this->carafeSensor.isTriggered()) {
        printMessageContext("Carafe was not seated on the warming plate, placing now", "Human Interaction");
        this->carafeSensor.trigger(true);
    };

    const TanksStatus tanksStatus = this->checkTanks();

    if (!tanksStatus.isReady) {
        // TODO: Throw or something here, or just log it?
        if (this->carafe.isFull()) {
            printMessageContext("Carafe was full, emptying now", "Human Interaction");
            this->carafe.empty();
        }

        if (this->boiler.isEmpty()) {
            printMessageContext("Boiler was empty, filling now", "Human Interaction");

            this->boiler.fill([this](double val) {
                bool isLast = val == this->boiler.getMaxCapacity();
                ProgressBar::percentage((int) val, (int) this->boiler.getMaxCapacity(), "Filling boiler...", isLast);
            }, 20);
        }

        this->boiler.checkWaterReady(this->brewIndicator, [](double val) {
            ProgressBar::temperature(val, 100.0, "Boiling...", (val == 100.0));
        });
    }

    printMessage("Ready to brew!");
}


/// MARK - Private
void CoffeeMaker::brewTick() {

}


/**
 * Checks the Boiler/Water and Carafe to see if we have enough water to even make coffee, or if the carafe has space available
 * @return TanksStatus
 */
TanksStatus CoffeeMaker::checkTanks() {
    // Readable, yes
    bool isReady = !this->boiler.isEmpty() && !this->carafe.isFull() && this->boiler.isReady();

    return {
            this->carafe.getCurrentCapacity(),
            this->boiler.getCurrentCapacity(),
            isReady
    };
}

void CoffeeMaker::setupFilterListeners(BrewStrength strength) {
    string grindsName = BrewStrengthConverter::humanReadable(strength) + " Grinds";
    this->currentGrinds = CoffeeGrinds(grindsName, strength);

    function<void(Consumable *)> grindsCallback = [this](Consumable *consumable) {
        auto *grinds = dynamic_cast<CoffeeGrinds *>(consumable);

        if (grinds->isConsumed()) {
            printMessage("Coffee Grinds are now consumed");
        }

        if (grinds->isEmpty()) {
            printMessage("No coffee grinds in machine");
        }
    };

    function<void(Consumable *)> filterCallback = [this](Consumable *consumable) {
        auto *filter = dynamic_cast<CoffeeFilter *>(consumable);

        if (filter->isConsumed()) {
            printMessageContext("Has been consumed", filter->getName());
        }

        if (filter->isEmpty()) {
            printMessageContext("Currently empty", filter->getName());
        } else {
            printMessageContext("Filled with " + filter->getGrinds().getName(), filter->getName());
        }
    };

    this->currentGrinds.watchConsumable(grindsCallback);
    this->mainFilter.fill(currentGrinds);
    this->mainFilter.watchConsumable(filterCallback);
}

void CoffeeMaker::setupCarafeListener(bool carafeAvailable) {
    function<void(bool)> carafeSensorCallback = [this](bool isAvailable) {
        printMessageContext((isAvailable ? "Available" : "Unavailable"), "Carafe");
    };


    this->carafeSensor.watchSensorTriggered(carafeSensorCallback, false);
    this->carafeSensor.trigger(carafeAvailable);
}

void CoffeeMaker::setupIndicators() {
    function<void(IndicatorStatus)> brewIndicatorCallback = [this](IndicatorStatus status) {
        string statusMessage = "Off";

        if (status.solid) {
            statusMessage = "Lit - (Solid/Brewing)";
        } else if (status.blinking) {
            statusMessage = "Lit - (Blinking/Waiting)";
        }

        printMessageContext(statusMessage, "Brew Indicator Light");
    };

    function<void(IndicatorStatus)> plateIndicatorCallback = [this](IndicatorStatus status) {
        string statusMessage = "Off";

        if (status.solid) {
            statusMessage = "Lit - (Solid/Warm)";
        } else if (status.blinking) {
            statusMessage = "Lit - (Blinking/Waiting)";
        }

        printMessageContext(statusMessage, "Plate Indicator Light");
    };

    this->plateHeaterIndicator.listen(plateIndicatorCallback);
    this->brewIndicator.listen(brewIndicatorCallback);
}

void CoffeeMaker::setupBoilerListener(double initialTemperature = 0.0, bool boilerFilled = false) {
    function<void(double)> boilerTemperatureCallback = [this](double temperature) {
        printTemperatureContext("Contents are at ", "Boiler", temperature);
    };

    function<void(bool)> boilerFilledCallback = [this](bool empty) {
        printMessageContext((empty ? "Empty" : "Full"), "Boiler");
    };

    function<void(bool)> boilerHeatStateCallback = [this](bool heating) {
        printMessageContext(string("Contents are ") + (heating ? "heating" : "not heating"), "Boiler");
    };

    this->boiler.watchTemperatureValue(boilerTemperatureCallback, (initialTemperature == 100.0));
    this->boiler.watchHeatingState(boilerHeatStateCallback, false);
    this->boiler.watchFilledStatus(boilerFilledCallback, boilerFilled);
    this->boiler.setInitialTemperature(initialTemperature);
}



