cmake_minimum_required(VERSION 3.5)
project(MightyGumballLib VERSION 1.0.0)

set(SOURCES
    machine.cpp
    states/state.cpp
    states/has-quater-state.cpp
    states/no-quater-state.cpp
    states/sold-state.cpp
    states/sold-out-state.cpp
    states/winner-state.cpp
)

add_library(mightyGumballLib STATIC ${SOURCES})

set_target_properties(mightyGumballLib PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED TRUE
    LANGUAGE CXX
)
