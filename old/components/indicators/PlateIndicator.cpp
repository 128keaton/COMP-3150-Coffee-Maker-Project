//
// Created by Keaton Burleson on 11/28/21.
//

#include "PlateIndicator.h"

bool PlateIndicator::isIndicatorLit() {
    return this->plateHeaterOn;
}

void PlateIndicator::setOn() {
    this->plateHeaterOn = true;
}

void PlateIndicator::setOff() {
    this->plateHeaterOn = false;
}