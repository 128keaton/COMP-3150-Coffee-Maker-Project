//
// Created by Keaton Burleson on 11/28/21.
//

#include "BaseHeater.h"

#include <utility>

BaseHeater::BaseHeater(string name) {
    this->heating = false;
    this->name = std::move(name);
}

string BaseHeater::getName() {
    return this->name;
}

void BaseHeater::setHeating(bool isHeating) {
    this->heating = isHeating;
}

bool BaseHeater::isHeating() const {
    return this->heating;
}

