cmake_minimum_required(VERSION 3.5)
project(WeatherStationExe VERSION 1.0.0)

set(SOURCES
    weather-station.cpp
)

add_executable(weatherStation ${SOURCES})
set_target_properties(weatherStation PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED TRUE
)
target_include_directories(weatherStation
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../lib
)
target_link_libraries(weatherStation
    weatherStationLib
)
