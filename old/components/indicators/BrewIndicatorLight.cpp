//
// Created by Keaton Burleson on 11/28/21.
//

#include "BrewIndicatorLight.h"

bool BrewIndicatorLight::isIndicatorLit() {
    return this->isBrewing;
}

void BrewIndicatorLight::setOn() {
    this->isBrewing = true;
}

void BrewIndicatorLight::setOff() {
    this->isBrewing = false;
}
