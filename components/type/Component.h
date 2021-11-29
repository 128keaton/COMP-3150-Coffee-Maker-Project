//
// Created by Keaton Burleson on 11/28/21.
//

#ifndef HONORSPROJECT_COMPONENT_H
#define HONORSPROJECT_COMPONENT_H

#include <functional>
#include <string>

#include "ComponentType.h"

using std::string, std::function;

class Component {

public:
    Component(
            const string &componentName,
            ComponentType componentType
    ) {
        this->name = componentName;
        this->type = componentType;
    }

    string getName() {
        return this->name;
    }

    ComponentType getType() {
        return this->type;
    }

protected:
    string name;
    ComponentType type;
};


#endif //HONORSPROJECT_COMPONENT_H
