//
// Created by Keaton Burleson on 11/28/21.
//

#ifndef HONORSPROJECT_COFFEEGRINDS_H
#define HONORSPROJECT_COFFEEGRINDS_H


#include "Consumable.h"

class CoffeeGrinds: public Consumable {
public:
    CoffeeGrinds();
    string getName() override;
    void setConsumed() override;
};


#endif //HONORSPROJECT_COFFEEGRINDS_H
