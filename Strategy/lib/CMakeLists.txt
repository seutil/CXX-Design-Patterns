cmake_minimum_required(VERSION 3.5)
project(DuckUSimLib VERSION 1.0.0)

set(SOURCES
    behaviors.hpp
    ducks.hpp
)

add_library(duckUSimLib STATIC ${SOURCES})
set_target_properties(duckUSimLib PROPERTIES
    CXX_STANDARD 17
    LINKER_LANGUAGE CXX
)
