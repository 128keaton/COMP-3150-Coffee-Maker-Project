//
// Created by Keaton Burleson on 11/28/21.
//

#include <string>

#ifndef HONORSPROJECT_COFFEEADDITIVE_H
#define HONORSPROJECT_COFFEEADDITIVE_H


using namespace std;

class CoffeeAdditive {
public:
    virtual double getCost() = 0;
    virtual string getName() = 0;

protected:
    double cost;
    string name;

};


#endif //HONORSPROJECT_COFFEEADDITIVE_H
