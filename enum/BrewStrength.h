//
// Created by Keaton Burleson on 11/29/21.
//

#ifndef HONORSPROJECT_BREWSTRENGTH_H
#define HONORSPROJECT_BREWSTRENGTH_H

#include <string>
#include <stdexcept>

using std::string, std::invalid_argument;

enum BrewStrength {
    REGULAR, STRONG, WEAK
};

class BrewStrengthConverter {
public:
    static BrewStrength get(const string &raw) {
        if (raw.starts_with("WEAK")) {
            return WEAK;
        } else if (raw.starts_with("STRONG")) {
            return STRONG;
        } else if (raw.starts_with("REGULAR")) {
            return REGULAR;
        }

        throw invalid_argument(raw + " is not a valid value for BrewStrength");
    }

    static string humanReadable(BrewStrength strength) {
        switch (strength) {
            case REGULAR:
                return "Regular";
            case STRONG:
                return "Strong";
            case WEAK:
                return "Weak";
        }
    }
};

#endif //HONORSPROJECT_BREWSTRENGTH_H
