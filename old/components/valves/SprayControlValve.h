//
// Created by Keaton Burleson on 11/28/21.
//

#ifndef HONORSPROJECT_SPRAYCONTROLVALVE_H
#define HONORSPROJECT_SPRAYCONTROLVALVE_H


#include "../../enums/BrewStrength.h"
#include "Valve.h"

class SprayControlValve: public Valve {
public:
    void open() override;
    void close() override;
    void setBrewStrength(BrewStrength strength);
    BrewStrength getBrewStrength();

private:
    BrewStrength brewStrength;
};


#endif //HONORSPROJECT_SPRAYCONTROLVALVE_H
