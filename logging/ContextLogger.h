//
// Created by Keaton Burleson on 11/29/21.
//

#ifndef HONORSPROJECT_CONTEXTLOGGER_H
#define HONORSPROJECT_CONTEXTLOGGER_H

#include <string>
#include <iostream>

using std::string,
std::cout,
std::endl;

class ContextLogger {
public:
    explicit ContextLogger(string baseCTX) {
        this->baseContext = std::move(baseCTX);
    }

    void printMessage(const string &msg, bool appendNewline = false);
    void printMessageContext(const string &msg, const string &context, bool appendNewline = false);
    void printTemperature(const string &msg, double temperature);
    void printTemperatureContext(const string &msg, const string &context, double temperature);

protected:
    string baseContext;
};


#endif //HONORSPROJECT_CONTEXTLOGGER_H
