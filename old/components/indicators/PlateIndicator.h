//
// Created by Keaton Burleson on 11/28/21.
//

#ifndef HONORSPROJECT_PLATEINDICATOR_H
#define HONORSPROJECT_PLATEINDICATOR_H


#include "Indicator.h"

class PlateIndicator: public Indicator {
public:
    bool isIndicatorLit() override;
    void setOn() override;
    void setOff() override;

private:
    bool plateHeaterOn = false;
};


#endif //HONORSPROJECT_PLATEINDICATOR_H
