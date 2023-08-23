cmake_minimum_required(VERSION 3.5)
project(BistroExe VERSION 1.0.0)

set(SOURCES
    menus.cpp
    waitress.cpp
)

add_library(bistroLib STATIC ${SOURCES})

set_target_properties(bistroLib PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED TRUE
)
