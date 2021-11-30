//
// Created by Keaton Burleson on 11/29/21.
//

#ifndef HONORSPROJECT_HEATER_H
#define HONORSPROJECT_HEATER_H

#include <string>
#include <cmath>
#include <unistd.h>

#include "Sensor.h"

using std::string;

class Heater : public Sensor {
public:
    explicit Heater(const string &componentName) : Sensor(componentName, 0.0, false, HEATER) {
    }

    [[nodiscard]] bool isHeating() const {
        return this->heating;
    }

    void setHeating(bool isNowHeating) {
        const bool shouldUpdate = (isNowHeating != this->heating);
        this->heating = isNowHeating;

        if (shouldUpdate) {
            this->updateHeatingStatus();
        }
    }

    void watchTemperatureValue(std::function<void(double)> &cb, bool emitInitial = true) {
       this->watchSensorValue(cb, emitInitial);
    }

    void watchFilledStatus(std::function<void(bool)> &cb, bool emitInitial = true) {
        this->watchSensorTriggered(cb, emitInitial);
    }

    void watchHeatingState(std::function<void(bool)> &cb, bool emitInitial = true) {
        this->heatingCallback = cb;

        if (emitInitial) {
            cb(this->heating);
        }
    }

private:
    friend class Boiler;

protected:
    bool heating = false;
    std::function<void(bool)> heatingCallback = nullptr;

    void updateTemperature(double value, bool emit = false) {
        this->setValue(value, emit);
    }

    double getTemperature() {
        return this->getValue();
    }

    void updateHeatingStatus() {
        if (this->heatingCallback != nullptr) {
            this->heatingCallback(this->heating);
        }
    }
};

#endif //HONORSPROJECT_HEATER_H
