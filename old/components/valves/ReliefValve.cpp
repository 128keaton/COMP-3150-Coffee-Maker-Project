//
// Created by Keaton Burleson on 11/28/21.
//

#include "ReliefValve.h"

void ReliefValve::open() {
    this->isOpened = true;
}

void ReliefValve::close() {
    this->isOpened = false;
}
