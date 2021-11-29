//
// Created by Keaton Burleson on 11/29/21.
//

#ifndef HONORSPROJECT_INDICATOR_H
#define HONORSPROJECT_INDICATOR_H

#include <string>

#include "type/Component.h"
#include "../status/IndicatorStatus.h"

using std::string;

class Indicator : public Component {
public:
    explicit Indicator(const string &name) : Component(name, INDICATOR) {
    }

    [[nodiscard]] bool isSolid() const {
        return this->solid;
    }

    void listen(function<void(IndicatorStatus)> &callback) {
        this->updated = callback;
        this->update();
    }

    void setSolid(bool isSolid = true) {
        if (this->blink && isSolid) {
            this->blink = false;
        }

        this->solid = isSolid;
        this->update();
    }

    [[nodiscard]] bool isBlinking() const {
        return this->blink;
    }

    void setBlinking(bool isBlinking = true) {
        if (this->solid && isBlinking) {
            this->solid = false;
        }

        this->blink = isBlinking;
        this->update();
    }

protected:
    bool solid = false;
    bool blink = false;
    function<void(IndicatorStatus)> updated = nullptr;

    void update() {
        if (this->updated == nullptr) {
            return;
        }

        this->updated(
                {
                        this->isBlinking(),
                        this->isSolid()
                }
        );
    }
};

#endif //HONORSPROJECT_INDICATOR_H
