//
// Created by Keaton Burleson on 11/29/21.
//

#ifndef HONORSPROJECT_INDICATOR_H
#define HONORSPROJECT_INDICATOR_H

#include <string>

#include "type/Component.h"

using std::string;

class Indicator: public Component {
public:
    explicit Indicator(const string& name): Component(name, INDICATOR) {
    }

    [[nodiscard]] bool isSolid() const {
        return this->solid;
    }

    void setSolid(bool isSolid) {
        if (this->blink && isSolid) {
            this->blink = false;
        }
        this->solid = isSolid;
    }

    [[nodiscard]] bool isBlinking() const {
        return this->blink;
    }

    void setBlinking(bool isBlinking) {
        if (this->solid && isBlinking) {
            this->solid = false;
        }

        this->blink = isBlinking;
    }

protected:
    bool solid = false;
    bool blink = false;
};

#endif //HONORSPROJECT_INDICATOR_H
