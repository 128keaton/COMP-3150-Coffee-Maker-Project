//
// Created by Keaton Burleson on 11/28/21.
//

#include "Boiler.h"

#include <utility>

Boiler::Boiler(double capacity, string units) {
    this->capacity = capacity;
    this->units = std::move(units);
}

bool Boiler::isEmpty() {
    return this->percentFull == 0.0;
}

bool Boiler::isFull() {
    return this->percentFull == 100.0;
}

void Boiler::fillWater() {
    this->percentFull = 100.0;
}

void Boiler::startBoiling() {
    if (this->tankHeater.isHeating()) {
        return;
    }

    this->tankHeater.setHeating(true);
}

double Boiler::takeWater(double waterToTake) {
    this->percentFull -= waterToTake;

    if (this->isEmpty()) {
       this->tankHeater.setHeating(false);
    }

    return waterToTake;
}

double Boiler::getPercentFull() {
    return this->percentFull;
}


