cmake_minimum_required(VERSION 3.20)
project(HonorsProject)

set(CMAKE_CXX_STANDARD 20)

add_executable(HonorsProject main.cpp components/type/Component.h components/type/ComponentType.h CoffeeMaker.cpp CoffeeMaker.h components/Heater.h components/Boiler.h components/Tank.h components/Sensor.h components/Indicator.h status/TankStatus.h helpers/ProgressBar.h status/IndicatorStatus.h)
