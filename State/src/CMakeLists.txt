cmake_minimum_required(VERSION 3.5)
project(MightyGumballExe VERSION 1.0.0)

set(SOURCES
    mighty-gumball.cpp
)

add_executable(mightyGumball ${SOURCES})

set_target_properties(mightyGumball PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED TRUE
)
target_include_directories(mightyGumball
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../lib
)
target_link_libraries(mightyGumball
    mightyGumballLib
)
