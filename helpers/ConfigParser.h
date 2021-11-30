//
// Created by Keaton Burleson on 11/29/21.
//

#ifndef HONORSPROJECT_CONFIGPARSER_H
#define HONORSPROJECT_CONFIGPARSER_H

#include <fstream>
#include <iostream>
#include "inipp.h"
#include "../types/BrewConfig.h"

using std::ifstream,
inipp::Ini,
inipp::get_value,
std::cout,
std::endl;

class ConfigParser {
public:
    static BrewConfig getBrewConfig(const string &path = "./config.ini", bool printParsed = false) {
        Ini<char> rawConfig;
        string rawBrewStrength;
        double finishAt = 100.0;
        bool carafeAvailable = false;
        bool carafeEmpty = false;
        bool boilerFilled = false;
        bool boilerHot = false;

        ifstream is(path);

        rawConfig.parse(is);

        // Parse Brew Section
        get_value(rawConfig.sections["Brew"], "Strength", rawBrewStrength);
        get_value(rawConfig.sections["Brew"], "FinishAtPercentage", finishAt);

        // Parse Components Section
        get_value(rawConfig.sections["Components"], "CarafeAvailable", carafeAvailable);
        get_value(rawConfig.sections["Components"], "CarafeEmpty", carafeEmpty);
        get_value(rawConfig.sections["Components"], "BoilerFilled", boilerFilled);
        get_value(rawConfig.sections["Components"], "BoilerHot", boilerHot);

        // Convert the raw string to a BrewStrength type
        BrewStrength brewStrength = BrewStrengthConverter::get(rawBrewStrength);

        if (printParsed) {
            cout << "Brew Strength = " << BrewStrengthConverter::humanReadable(brewStrength) << endl;
            cout << "Finish At = " << finishAt << endl;
            cout << "Carafe Available = " << (carafeAvailable ? "Yes" : "No") << endl;
            cout << "Carafe Empty = " << (carafeEmpty ? "Yes" : "No") << endl;
            cout << "Boiler Filled = " << (boilerFilled ? "Yes" : "No") << endl;
            cout << "Boiler Hot = " << (boilerHot ? "Yes" : "No") << endl;
        }

        return {
                brewStrength,
                finishAt,
                carafeAvailable,
                carafeEmpty,
                boilerFilled,
                boilerHot,
        };
    }
};

#endif //HONORSPROJECT_CONFIGPARSER_H
