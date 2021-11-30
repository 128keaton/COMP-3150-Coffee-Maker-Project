//
// Created by Keaton Burleson on 11/29/21.
//


#include "ContextLogger.h"

/**
 * This function prints out a message with our pre-formatted context
 * @param msg - string message to print to the console
 */
void ContextLogger::printMessage(const string &msg, bool appendNewline) {
    if (appendNewline) {
        cout << '\n';
    }

    cout << "[" << this->baseContext << "] " << msg << endl;
}

/**
* This function prints out a message with our pre-formatted context and an additional context
* @param msg - string message to print to the console
*/
void ContextLogger::printMessageContext(const string &msg, const string &context, bool appendNewline) {
    printMessage(string("[" + context + "] " + msg), appendNewline);
}


/**
* This function prints out a message + temperature with our pre-formatted context
* @param msg - string message to print to the console
* @param temperature - Double temp to print to the console
*/
void ContextLogger::printTemperature(const string &msg, double temperature) {
    cout << "[" << this->baseContext << "] " << msg << temperature << "°C " << endl;
}

/**
 * This function prints out a message + temperature with our pre-formatted context
 * @param msg - string message to print to the console
 * @param context - Additional context
 * @param temperature - Double temp to print to the console
*/
void ContextLogger::printTemperatureContext(const string &msg, const string &context, double temperature) {
    this->printTemperature(string("[" + context + "] " + msg), temperature);
}