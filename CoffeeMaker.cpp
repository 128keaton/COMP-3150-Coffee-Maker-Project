//
// Created by Keaton Burleson on 11/29/21.
//

#include <iostream>
#include "CoffeeMaker.h"

using std::cout, std::endl;

void CoffeeMaker::brew() {
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


TanksStatus CoffeeMaker::checkTanks() {
    // Readable, yes
    bool isReady = !this->boiler.isEmpty() && !this->carafe.isFull() && !this->boiler.isReady();

    return {
            this->carafe.getCurrentCapacity(),
            this->boiler.getCurrentCapacity(),
            isReady
    };
}

void CoffeeMaker::fillWaterTank() {
    this->boiler.fill();
    printMessage("Boiler filled");
}

void CoffeeMaker::emptyCarafe() {
    this->carafe.empty();
    printMessage("Carafe emptied");
}

void CoffeeMaker::startBoiler() {
    this->boiler.startBoiling([](double val) {
        std::cout << "[Coffee Maker][Boiler]" << val << "*F" << endl;
    });
}

void CoffeeMaker::printMessage(const string &msg) {
    std::cout << "[Coffee Maker] " << msg << endl;
}

