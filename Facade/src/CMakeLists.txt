cmake_minimum_required(VERSION 3.5)
project(HomeCinemaExe VERSION 1.0.0)

set(SOURCES
    home-cinema.cpp
)

add_executable(homeCinema ${SOURCES})

set_target_properties(homeCinema PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED TRUE
)
target_include_directories(homeCinema
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../lib
)
target_link_libraries(homeCinema
    homeCinemaLib
)
