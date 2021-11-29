//
// Created by Keaton Burleson on 11/28/21.
//

#include "CoffeeFilter.h"

CoffeeFilter::CoffeeFilter() {
    this->isConsumed = false;
    this->name = "Coffee Filter";
}

void CoffeeFilter::setConsumed() {
    this->isConsumed = true;
}

string CoffeeFilter::getName() {
    return this->name;
}
