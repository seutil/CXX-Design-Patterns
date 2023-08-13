cmake_minimum_required(VERSION 3.5)
project(HomeStationExe VERSION 1.0.0)

set(SOURCES
    home-station.cpp
)

add_executable(homeStation ${SOURCES})

set_target_properties(homeStation PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED TRUE
)
target_include_directories(homeStation
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../lib
)
target_link_libraries(homeStation
    homeStationLib
)
