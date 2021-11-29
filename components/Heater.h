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
        this->heating = isNowHeating;
    }

private:
    friend class Boiler;

protected:
    bool heating = false;

    void updateTemperature(double value) {
        this->value = value;
    }

    double getTemperature() {
        return this->value;
    }
};

#endif //HONORSPROJECT_HEATER_H
