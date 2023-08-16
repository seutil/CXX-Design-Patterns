cmake_minimum_required(VERSION 3.5)
project(HomeCinemaExe VERSION 1.0.0)

set(SOURCES
    components.cpp
)

add_library(homeCinemaLib STATIC ${SOURCES})

set_target_properties(homeCinemaLib PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED TRUE
)
