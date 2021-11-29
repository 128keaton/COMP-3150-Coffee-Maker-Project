//
// Created by Keaton Burleson on 11/28/21.
//

#ifndef HONORSPROJECT_TANK_H
#define HONORSPROJECT_TANK_H

#include <string>

using namespace std;

class Tank {
public:
    virtual bool isEmpty() = 0;
    virtual bool isFull() = 0;
    virtual double getPercentFull() = 0;

protected:
    double capacity;
    double percentFull;
    string units;
};


#endif //HONORSPROJECT_TANK_H
