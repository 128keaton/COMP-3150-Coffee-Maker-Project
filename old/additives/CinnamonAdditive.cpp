//
// Created by Keaton Burleson on 11/28/21.
//

#include "CinnamonAdditive.h"

CinnamonAdditive::CinnamonAdditive() {
    this->cost = 0.50;
    this->name = "Cinnamon";
}

double CinnamonAdditive::getCost() {
    return cost;
}

string CinnamonAdditive::getName() {
   return "Cinnamon";
}
