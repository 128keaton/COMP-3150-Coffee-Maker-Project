//
// Created by Keaton Burleson on 11/29/21.
//

#ifndef HONORSPROJECT_COFFEEGRINDS_H
#define HONORSPROJECT_COFFEEGRINDS_H

#include "./type/Consumable.h"
#include "../enum/BrewStrength.h"

class CoffeeGrinds : public Consumable {
public:
    CoffeeGrinds(const string &name, BrewStrength strength, bool consumed = false) : Consumable(COFFEE_GROUNDS, name,
                                                                                                consumed) {
        this->brewStrength = strength;
    }

    CoffeeGrinds() : Consumable(COFFEE_GROUNDS, "",
                                true) {
        this->brewStrength = REGULAR;
    }

protected:
    BrewStrength brewStrength;
};

#endif //HONORSPROJECT_COFFEEGRINDS_H
