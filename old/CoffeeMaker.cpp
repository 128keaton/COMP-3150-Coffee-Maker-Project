//
// Created by Keaton Burleson on 11/28/21.
//

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include "CoffeeMaker.h"
#include "Loop.h"

using namespace std;

BrewStatus CoffeeMaker::getStatus() {
    return this->status;
}

bool CoffeeMaker::isPaused() {
    return this->getStatus() == PAUSED;
}

bool CoffeeMaker::isFinished() {
    return this->getStatus() == FINISHED;
}

bool CoffeeMaker::isBrewing() {
    return this->getStatus() == BREWING;
}

bool CoffeeMaker::isWaiting() {
    return this->getStatus() == WAITING;
}

void CoffeeMaker::setBrewing() {
    this->status = BREWING;

    double startProgress = this->progress != 0 ? this->progress : 0.0;
    double maxProgress = this->progressHaltAt != -1.0 ? this->progressHaltAt : 100.0;

    loop(maxProgress, startProgress, [&](double currentProgress) {
        double currentCoffee = this->boiler.takeWater(1.0);

        this->carafe.addBrewedCoffee(currentCoffee);
        this->plate.carafeUpdated(this->carafe);

        this->updateProgress(currentProgress);

        if (maxProgress < 100.0 && currentProgress == maxProgress) {
            // show brew pause message
        }

        sleep(1);
    });
}

void CoffeeMaker::setInterruptAt(double haltAt) {
    if (haltAt != -1.0 && this->progressHaltAt > 0.0) {
        this->progressHaltAt = haltAt;
    } else {
        this->progressHaltAt = -1.0;
    }
}

void CoffeeMaker::setFinished() {
    this->status = FINISHED;
    this->coffeeFilter.setConsumed();
}

void CoffeeMaker::updateProgress(double currentProgress) {
    this->progress = currentProgress;

    if (this->progress >= 100.0) {
        this->progress = 100.0;
        this->setFinished();
    }
}
