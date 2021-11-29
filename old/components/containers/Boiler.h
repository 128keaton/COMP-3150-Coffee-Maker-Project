//
// Created by Keaton Burleson on 11/28/21.
//

#ifndef HONORSPROJECT_BOILER_H
#define HONORSPROJECT_BOILER_H


#include "Tank.h"
#include "../heaters/BaseHeater.h"

class Boiler: public Tank {
public:
    Boiler(double capacity, string units);
    bool isEmpty() override;
    bool isFull() override;


    void fillWater();
    void startBoiling();
    double getPercentFull() override;
    double takeWater(double waterToTake);

private:
    BaseHeater tankHeater = BaseHeater("Boiler");
};


#endif //HONORSPROJECT_BOILER_H
