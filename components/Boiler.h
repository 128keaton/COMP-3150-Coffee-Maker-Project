//
// Created by Keaton Burleson on 11/29/21.
//

#ifndef HONORSPROJECT_BOILER_H
#define HONORSPROJECT_BOILER_H

#include <string>
#include <functional>
#include <unistd.h>

#include "type/Component.h"
#include "Tank.h"
#include "Heater.h"

using std::string, std::function;

class Boiler : public Heater, public Tank {
public:
    explicit Boiler(const string &name) : Heater(name), Tank(name, 300.0, true) {
    }


    void startBoiling(const std::function<void(double)> &p) {
        this->setHeating(true);

        for (unsigned t = 0; t <= 40 * 1000; t += 1000) {
            const double nextTemp = getEmulatedTemp((float) t, 0, 10, 40000);

            this->updateTemperature(nextTemp);
            p(nextTemp);

            usleep(15 * 5000 * 10);
        }
    }

    bool isReady() {
        return this->getTemperature() == 100.0;
    }

private:
    static double getEmulatedTemp(float t, float b, float c, float d) {
        return (-c / 2 * (cos(M_PI * t / d) - 1) + b) * 10;
    }
};

#endif //HONORSPROJECT_BOILER_H
