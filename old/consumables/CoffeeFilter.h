//
// Created by Keaton Burleson on 11/28/21.
//

#ifndef HONORSPROJECT_COFFEEFILTER_H
#define HONORSPROJECT_COFFEEFILTER_H

#include "Consumable.h"

class CoffeeFilter : public Consumable {
public:
    CoffeeFilter();

    string getName() override;
    void setConsumed() override;
};


#endif //HONORSPROJECT_COFFEEFILTER_H
