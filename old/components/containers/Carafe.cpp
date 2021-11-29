//
// Created by Keaton Burleson on 11/28/21.
//

#include "Carafe.h"

Carafe::Carafe(BrewStrength strength) {
    this->brewStrength = strength;
}

Carafe::Carafe() {
    this->brewStrength = REGULAR;
}

bool Carafe::isFull() {
    return this->percentFull == 100.0;
}

bool Carafe::isEmpty() {
    return this->percentFull == 0.0;
}

void Carafe::empty() {
    this->percentFull = 0.0;
}

void Carafe::addBrewedCoffee(double amount) {
    if (this->percentFull < 100.0) {
        this->percentFull += amount;
    }
}

double Carafe::takeBrewedCoffee(double amount) {
    if (this->percentFull < amount) {
        double amountTaken = this->percentFull;
        this->percentFull = 0.0;

        return amountTaken;
    }

    this->percentFull -= amount;

    return amount;
}

void Carafe::setBrewStrength(BrewStrength strength) {
    this->brewStrength = strength;
}

BrewStrength Carafe::getBrewStrength() {
    return this->brewStrength;
}

double Carafe::getPercentFull() {
    return this->percentFull;
}
