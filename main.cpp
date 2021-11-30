#include <string>
#include "helpers/ConfigParser.h"
#include "CoffeeMaker.h"


int main(int argc, char** argv) {
    BrewConfig config;

    if (argc > 1) {
        bool printConfig = false;

        if (argc > 2) {
            printConfig = (string(argv[2]).starts_with("-debug"));
        }

        config = ConfigParser::getBrewConfig(argv[1], printConfig);
    }

    CoffeeMaker coffeeMaker = CoffeeMaker(config);
    coffeeMaker.brew();
}
