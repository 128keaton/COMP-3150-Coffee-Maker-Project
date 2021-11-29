//
// Created by Keaton Burleson on 11/28/21.
//

#ifndef HONORSPROJECT_CINNAMONADDITIVE_H
#define HONORSPROJECT_CINNAMONADDITIVE_H

#include "CoffeeAdditive.h"

class CinnamonAdditive: public CoffeeAdditive {
public:
    CinnamonAdditive();
    double getCost() override;
    string getName() override;
};


#endif //HONORSPROJECT_CINNAMONADDITIVE_H
