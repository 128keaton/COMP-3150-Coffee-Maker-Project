//
// Created by Keaton Burleson on 11/29/21.
//

#ifndef HONORSPROJECT_FILTERBASKET_H
#define HONORSPROJECT_FILTERBASKET_H

#include "Sensor.h"
#include "../consumables/CoffeeFilter.h"

class FilterBasket : public Sensor {

public:
    explicit FilterBasket(const string &componentName) : Sensor(componentName, 0.0, false, BASKET) {
    }

    bool hasFilter() {
        return this->triggered && !this->currentFilter.isEmpty();
    }

    bool isReady() {
        return this->hasFilter() && this->currentFilter.isReady();
    }

    void replaceFilter(const CoffeeFilter& newFilter) {
        this->currentFilter = newFilter;
        this->triggered = !this->currentFilter.isEmpty();
    }

protected:
    CoffeeFilter currentFilter = CoffeeFilter();

};

#endif //HONORSPROJECT_FILTERBASKET_H
