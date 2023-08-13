cmake_minimum_required(VERSION 3.5)
project(HomeStationLib VERSION 1.0.0)

set(SOURCES
    home-elements.cpp
    home-commands.cpp
    home-remote-controller.cpp
)

add_library(homeStationLib STATIC ${SOURCES})

set_target_properties(homeStationLib PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED TRUE
)
