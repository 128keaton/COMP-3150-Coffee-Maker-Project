//
// Created by Keaton Burleson on 11/28/21.
//

#include "MochaAdditive.h"

MochaAdditive::MochaAdditive() {
    this->cost = 0.90;
    this->name = "Mocha";
}

double MochaAdditive::getCost() {
    return cost;
}

string MochaAdditive::getName() {
    return "Mocha";
}
