//
// Created by Keaton Burleson on 11/28/21.
//

#ifndef HONORSPROJECT_BASEHEATER_H
#define HONORSPROJECT_BASEHEATER_H

#include <string>

using namespace std;

class BaseHeater {
public:
    explicit BaseHeater(string name);
    void setHeating(bool heating);
    [[nodiscard]] bool isHeating() const;
    string getName();

protected:
    string name;
    bool heating;
};

#endif //HONORSPROJECT_BASEHEATER_H
