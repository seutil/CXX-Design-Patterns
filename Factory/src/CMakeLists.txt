cmake_minimum_required(VERSION 3.5)
project(PizzeriaExe VERSION 1.0.0)

set(SOURCES
    pizzeria.cpp
)

add_executable(pizzeriaExe ${SOURCES})

set_target_properties(pizzeriaExe PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED TRUE
)
target_include_directories(pizzeriaExe
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../lib
)
target_link_libraries(pizzeriaExe
    pizzeriaLib
)
