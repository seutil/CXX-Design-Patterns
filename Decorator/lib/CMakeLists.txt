cmake_minimum_required(VERSION 3.5)
project(StarbuzzLib VERSION 1.0.0)

set(SOURCES
    beverages.cpp
    beverage-condiments.cpp
)

add_library(starbuzzLib STATIC ${SOURCES})
set_target_properties(starbuzzLib PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED TRUE
)
