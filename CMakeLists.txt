cmake_minimum_required(VERSION 3.20)

include(FetchContent)

FetchContent_Declare(inipp
        GIT_REPOSITORY https://github.com/mcmtroffaes/inipp.git
        GIT_TAG 46248e4e93a2e63f9a1d0d8d9ad40bd6b3725df5
        )
FetchContent_MakeAvailable(inipp)

project(
        HonorsProject
        LANGUAGES CXX
        VERSION 1.0.0
)

set(CMAKE_CXX_STANDARD 20)

add_executable(HonorsProject main.cpp components/type/Component.h components/type/ComponentType.h CoffeeMaker.cpp CoffeeMaker.h components/Heater.h components/Boiler.h components/Tank.h components/Sensor.h components/Indicator.h status/TankStatus.h helpers/ProgressBar.h status/IndicatorStatus.h enum/BrewStrength.h helpers/ConfigParser.h types/BrewConfig.h components/FilterBasket.h consumables/type/Consumable.h consumables/type/ConsumableType.h consumables/CoffeeGrinds.h consumables/CoffeeFilter.h logging/ContextLogger.cpp logging/ContextLogger.h)

target_link_libraries(HonorsProject PRIVATE inipp::inipp)