//
// Created by Keaton Burleson on 11/28/21.
//

#include "SprayControlValve.h"

void SprayControlValve::open() {
    this->isOpened = true;
}

void SprayControlValve::close() {
    this->isOpened = true;
}

void SprayControlValve::setBrewStrength(BrewStrength strength) {
    this->brewStrength = strength;
}

BrewStrength SprayControlValve::getBrewStrength() {
    return this->brewStrength;
}
