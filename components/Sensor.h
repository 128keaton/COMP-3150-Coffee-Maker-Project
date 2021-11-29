//
// Created by Keaton Burleson on 11/29/21.
//

#ifndef HONORSPROJECT_SENSOR_H
#define HONORSPROJECT_SENSOR_H

#include <string>

#include "type/Component.h"

using std::string;

class Sensor : public Component {
public:
    explicit Sensor(const string &name, double value = 0.0, bool triggered = false, ComponentType type = SENSOR)
            : Component(name, type) {
        this->triggered = triggered;
        this->value = value;
    }

    [[nodiscard]] bool isTriggered() const {
        return this->triggered;
    }

    void trigger(bool isTriggered = true) {
        this->triggered = isTriggered;
    }

protected:
    bool triggered = false;
    double value = 0.0;
};

#endif //HONORSPROJECT_SENSOR_H
