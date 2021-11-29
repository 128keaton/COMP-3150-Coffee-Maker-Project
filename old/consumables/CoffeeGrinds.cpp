//
// Created by Keaton Burleson on 11/28/21.
//

#include "CoffeeGrinds.h"

CoffeeGrinds::CoffeeGrinds() {
    this->isConsumed = false;
    this->name = "Coffee Grinds";
}

string CoffeeGrinds::getName() {
    return name;
}

void CoffeeGrinds::setConsumed() {
    this->isConsumed = true;
}
