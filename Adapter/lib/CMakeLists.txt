cmake_minimum_required(VERSION 3.5)
project(AdapterLib VERSION 1.0.0)

set(SOURCES
    plugs.cpp
    power-sockets.cpp
    power-socket-adapters.cpp
)

add_library(adapterLib STATIC ${SOURCES})

set_target_properties(adapterLib PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED TRUE
)
