//
// Created by Keaton Burleson on 11/28/21.
//

#include "WhippedCreamAdditive.h"

WhippedCreamAdditive::WhippedCreamAdditive() {
    this->name = "Whipped Cream";
    this->cost = 1.25;
}

string WhippedCreamAdditive::getName() {
    return name;
}

double WhippedCreamAdditive::getCost() {
    return cost;
}
