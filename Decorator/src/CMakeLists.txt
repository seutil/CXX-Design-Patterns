cmake_minimum_required(VERSION 3.5)
project(StarBuzzExe VERSION 1.0.0)

set(SOURCES
    starbuzz.cpp
)

add_executable(starbuzz ${SOURCES})
set_target_properties(starbuzz PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED TRUE
)
target_include_directories(starbuzz
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../lib
)
target_link_libraries(starbuzz
    starbuzzLib
)
