cmake_minimum_required(VERSION 3.5)
project(PizzeriaLib VERSION 1.0.0)

set(SOURCES
    pizza.cpp
)

add_library(pizzeriaLib STATIC ${SOURCES})

set_target_properties(pizzeriaLib PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED TRUE
)
