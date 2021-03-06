//
// Created by Keaton Burleson on 11/29/21.
//

#ifndef HONORSPROJECT_TANK_H
#define HONORSPROJECT_TANK_H

#include <string>

#include "type/Component.h"
#include "Sensor.h"
#include "../status/TankStatus.h"

using std::string;

class Tank : public Sensor {
public:
    double maxCapacity;

    explicit Tank(const string &name = "Water Tank", double tankCapacity = 100.0, bool hasHeater = false) :
            Sensor(name, 0.0, false, (hasHeater ? BOILER : TANK)) {
        this->maxCapacity = tankCapacity;
    }

    [[nodiscard]] bool isFull() const {
        return this->value == this->maxCapacity;
    }

    [[nodiscard]] bool isEmpty() const {
        return this->value == 0.0;
    }

    void fill(const std::function<void(double)> &statusCallback, double speed = 10) {
        for(int i = 0; i <= this->maxCapacity; i += speed) {
            this->value = i;

            if (this->value <= this->maxCapacity) {
                statusCallback(this->value);
                usleep(15 * 5000 * 10);
            }
        }

        this->triggered = false;
    }

    void fillNow() {
        this->value = this->maxCapacity;
        this->triggered = false;
    }

    void empty() {
        this->value = 0.0;
        this->triggered = true;
    }

    double take(double amount) {
        double returnAmount = amount;

        if (amount > this->value) {
            returnAmount = this->value;
            this->value = 0;

            this->updateTriggered();

            return returnAmount;
        }

        this->value -= amount;
        this->updateTriggered();

        return returnAmount;
    }

    double getCurrentCapacity() {
        return this->value;
    }

    [[nodiscard]] double getMaxCapacity() const {
        return this->maxCapacity;
    }
};

#endif //HONORSPROJECT_TANK_H
