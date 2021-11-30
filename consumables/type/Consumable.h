//
// Created by Keaton Burleson on 11/29/21.
//

#ifndef HONORSPROJECT_CONSUMABLE_H
#define HONORSPROJECT_CONSUMABLE_H

#include <functional>
#include <string>
#include "ConsumableType.h"


using std::string, std::function;

class Consumable {
public:
    virtual ~Consumable() = default;
    Consumable(ConsumableType type, const string &name, bool consumed = false) {
        this->consumed = consumed;
        this->name = name;
        this->consumableType = type;
    }

    void watchConsumable(std::function<void(Consumable*)> &cb) {
        this->callback = cb;
        cb(this);
    }

    [[nodiscard]] bool isConsumed() const {
        return this->consumed;
    }

    void setConsumed(bool isConsumed = true) {
        this->consumed = isConsumed;
        this->update();
    }

    bool isEmpty() {
        return this->name.empty();
    }

    string getName() {
        return this->name;
    }

protected:
    bool consumed;
    string name;
    ConsumableType consumableType;
    std::function<void(Consumable*)> callback = nullptr;

    void update() {
        if (this->callback != nullptr) {
            this->callback(this);
        }
    }
};

#endif //HONORSPROJECT_CONSUMABLE_H
