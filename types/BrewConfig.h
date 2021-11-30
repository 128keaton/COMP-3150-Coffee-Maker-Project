//
// Created by Keaton Burleson on 11/29/21.
//

#ifndef HONORSPROJECT_BREWCONFIG_H
#define HONORSPROJECT_BREWCONFIG_H

#include "../enum/BrewStrength.h"

struct BrewConfig {
    BrewStrength strength = REGULAR;
    double finishAt = 100.0;
    bool carafeAvailable = false;
    bool carafeEmpty = false;
    bool boilerFilled = false;
    bool boilerHot = false;
};

#endif //HONORSPROJECT_BREWCONFIG_H
