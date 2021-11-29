//
// Created by Keaton Burleson on 11/28/21.
//

#ifndef HONORSPROJECT_BREWINDICATORLIGHT_H
#define HONORSPROJECT_BREWINDICATORLIGHT_H


#include "Indicator.h"

class BrewIndicatorLight: public Indicator {
public:
    bool isIndicatorLit() override;
    void setOn() override;
    void setOff() override;

private:
    bool isBrewing = false;
};


#endif //HONORSPROJECT_BREWINDICATORLIGHT_H
