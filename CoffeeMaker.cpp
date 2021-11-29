//
// Created by Keaton Burleson on 11/29/21.
//

#include "CoffeeMaker.h"

/// MARK - Public

CoffeeMaker::CoffeeMaker() {
    function<void(IndicatorStatus)> brewIndicatorCallback = [](IndicatorStatus status) {
        if (!status.solid && !status.blinking) {
            printMessage("Brew Indicator Light - Off");
        } else if (status.solid) {
            printMessage("Brew Indicator Light - Lit (Solid/Brewing)");
        } else if (status.blinking) {
            printMessage("Brew Indicator Light - Lit (Blinking/Waiting)");
        }
    };

    function<void(IndicatorStatus)> plateIndicatorCallback = [](IndicatorStatus status) {
        if (!status.solid && !status.blinking) {
            printMessage("Plate Indicator Light - Off");
        } else if (status.solid) {
            printMessage("Plate Indicator Light - Lit (Solid/Warm)");
        } else if (status.blinking) {
            printMessage("Plate Indicator Light - Lit (Blinking/Waiting)");
        }
    };

    this->plateHeaterIndicator.listen(plateIndicatorCallback);
    this->brewIndicator.listen(brewIndicatorCallback);
}

/**
 * Kicks off the brew cycle
 */
void CoffeeMaker::brew() {
    if (!this->carafeSensor.isTriggered()) {
        printMessage("Carafe was not seated on the warming plate, placing now");
        this->carafeSensor.trigger(true);
    };

    const TanksStatus tanksStatus = this->checkTanks();

    if (!tanksStatus.isReady) {
        // TODO: Throw or something here, or just log it?
        if (this->carafe.isFull()) {
            printMessage("Carafe was full, emptying now");
            this->emptyCarafe();
        }

        if (this->boiler.isEmpty()) {
            printMessage("Boiler was empty, filling now");
            this->fillWaterTank();
        }

        if (!this->boiler.isReady()) {
            printMessage("Boiler did not contain warm water, heating now");
            this->startBoiler();
        }
    }
}

/**
 * Fill the Boiler/Water tank completely
 */
void CoffeeMaker::fillWaterTank() {
    this->boiler.fill();
    printMessage("Boiler filled");
}

/**
 * Empties the carafe completely
 */
void CoffeeMaker::emptyCarafe() {
    this->carafe.empty();
    printMessage("Carafe emptied");
}


/// MARK - Private
void CoffeeMaker::brewTick() {

}

/**
 * Starts boiling the water in the Boiler
 */
void CoffeeMaker::startBoiler() {
    // Start blinking the brew indicator to show that we are boiling
    this->brewIndicator.setBlinking();

    // Starts the boiling tick with our callback to our progress bar
    this->boiler.startBoiling([](double val) {
        ProgressBar::temperature(val, 100.0, "Boiling...");
    });

    // Notify the user that the boiler is ready
    printMessage("Boiler full of hot water and ready", true);
}

/**
 * Checks the Boiler/Water and Carafe to see if we have enough water to even make coffee, or if the carafe has space available
 * @return TanksStatus
 */
TanksStatus CoffeeMaker::checkTanks() {
    // Readable, yes
    bool isReady = !this->boiler.isEmpty() && !this->carafe.isFull() && !this->boiler.isReady();

    return {
            this->carafe.getCurrentCapacity(),
            this->boiler.getCurrentCapacity(),
            isReady
    };
}

/**
 * This function prints out a message with our pre-formatted context
 * @param msg - string message to print to the console
 */
void CoffeeMaker::printMessage(const string &msg, bool appendNewline) {
    if (appendNewline) {
        cout << '\n';
    }

    cout << "[Coffee Maker] " << msg << endl;
}


