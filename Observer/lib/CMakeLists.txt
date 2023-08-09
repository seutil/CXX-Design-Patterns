cmake_minimum_required(VERSION 3.5)
project(WeatherStationLib VERSION 1.0.0)

set(SOURCES
    weather-displays.cpp
    weather-station.cpp
)
add_library(weatherStationLib STATIC ${SOURCES})
set_target_properties(weatherStationLib PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED TRUE
)
