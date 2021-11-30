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
        const bool shouldUpdate = (this->triggered != isTriggered);

        this->triggered = isTriggered;

        if (shouldUpdate) {
            this->updateTriggered();
        }
    }

    void watchSensorTriggered(std::function<void(bool)> &cb, bool emitInitial = true) {
        this->triggeredCallback = cb;

        if (emitInitial) {
            cb(this->triggered);
        }
    }

    void watchSensorValue(std::function<void(double)> &cb, bool emitInitial = true) {
        this->valueCallback = cb;

        if (emitInitial) {
            cb(this->value);
        }
    }

protected:
    bool triggered = false;
    double value = 0.0;
    std::function<void(bool)> triggeredCallback = nullptr;
    std::function<void(double)> valueCallback = nullptr;

    void updateTriggered() {
        if (this->triggeredCallback != nullptr) {
            this->triggeredCallback(this->triggered);
        }
    }

    void updateValue() {
        if (this->valueCallback != nullptr) {
            this->valueCallback(this->value);
        }
    }

    void setValue(double newValue, bool emit = false) {
        const bool shouldUpdate = (this->value != newValue) && emit;

        this->value = newValue;

        if (shouldUpdate) {
            this->updateValue();
        }
    }

    [[nodiscard]] double getValue() const {
        return this->value;
    }
};

#endif //HONORSPROJECT_SENSOR_H
