//
// Created by Keaton Burleson on 11/29/21.
//

#ifndef HONORSPROJECT_COFFEEFILTER_H
#define HONORSPROJECT_COFFEEFILTER_H

#include "./type/Consumable.h"
#include "CoffeeGrinds.h"

class CoffeeFilter : public Consumable {
public:
    explicit CoffeeFilter(const string &name, bool consumed = false) : Consumable(COFFEE_FILTER, name, consumed) {
    }

    CoffeeFilter() : Consumable(COFFEE_FILTER, "", true) {}

    bool isConsumed() {
        if (this->hasGrinds()) {
            return this->grinds.isConsumed() || this->consumed;
        }

        return this->consumed;
    }


    bool isReady() {
        return !this->consumed && this->hasGrinds();
    }

    bool hasGrinds() {
        return !this->grinds.isEmpty();
    }

    void replace() {
        this->consumed = false;
        this->grinds = CoffeeGrinds();
    }

    void fill(const CoffeeGrinds &coffeeGrinds) {
        this->grinds = coffeeGrinds;
    }

    CoffeeGrinds getGrinds() {
        return this->grinds;
    }

protected:
    CoffeeGrinds grinds = CoffeeGrinds();
};


#endif //HONORSPROJECT_COFFEEFILTER_H
