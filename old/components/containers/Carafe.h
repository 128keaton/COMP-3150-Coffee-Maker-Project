//
// Created by Keaton Burleson on 11/28/21.
//

#ifndef HONORSPROJECT_CARAFE_H
#define HONORSPROJECT_CARAFE_H


#include "Tank.h"
#include "../../enums/BrewStrength.h"

class Carafe: public Tank {
public:
    Carafe();
    explicit Carafe(BrewStrength strength);
    bool isEmpty() override;
    bool isFull() override;
    double getPercentFull() override;

    void empty();
    void addBrewedCoffee(double amount);
    double takeBrewedCoffee(double amount);
    void setBrewStrength(BrewStrength strength);
    BrewStrength getBrewStrength();

private:
    BrewStrength brewStrength;
};


#endif //HONORSPROJECT_CARAFE_H
