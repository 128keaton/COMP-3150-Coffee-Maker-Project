//
// Created by Keaton Burleson on 11/28/21.
//

#ifndef HONORSPROJECT_RELIEFVALVE_H
#define HONORSPROJECT_RELIEFVALVE_H


#include "Valve.h"

class ReliefValve: public Valve {
public:
    void open() override;
    void close() override;
};


#endif //HONORSPROJECT_RELIEFVALVE_H
