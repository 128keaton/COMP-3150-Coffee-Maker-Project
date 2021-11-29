//
// Created by Keaton Burleson on 11/28/21.
//

#ifndef HONORSPROJECT_MOCHAADDITIVE_H
#define HONORSPROJECT_MOCHAADDITIVE_H

#include "CoffeeAdditive.h"


class MochaAdditive: public CoffeeAdditive {
public:
    MochaAdditive();
    double getCost() override;
    string getName() override;
};


#endif //HONORSPROJECT_MOCHAADDITIVE_H
