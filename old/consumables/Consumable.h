//
// Created by Keaton Burleson on 11/28/21.
//

#ifndef HONORSPROJECT_CONSUMABLE_H
#define HONORSPROJECT_CONSUMABLE_H

#include <string>

using namespace std;

class Consumable {

public:
    virtual void setConsumed() = 0;
    virtual string getName() = 0;

protected:
    string name;
    bool isConsumed;
};

#endif //HONORSPROJECT_CONSUMABLE_H
