//
// Created by Keaton Burleson on 11/28/21.
//

#ifndef HONORSPROJECT_WHIPPEDCREAMADDITIVE_H
#define HONORSPROJECT_WHIPPEDCREAMADDITIVE_H

#include "CoffeeAdditive.h"

class WhippedCreamAdditive: public CoffeeAdditive {
public:
    WhippedCreamAdditive();

    double getCost() override;
    string getName() override;
};


#endif //HONORSPROJECT_WHIPPEDCREAMADDITIVE_H
