cmake_minimum_required(VERSION 3.5)
project(AdapterExe VERSION 1.0.0)

set(SOURCES
    adapter.cpp
)

add_executable(adapter ${SOURCES})

set_target_properties(adapter PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED TRUE
)
target_include_directories(adapter
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../lib
)
target_link_libraries(adapter
    adapterLib
)
