cmake_minimum_required(VERSION 3.16)
project(placedata)
set( COMP_FLAGS -std=c++2a -Wall -Wextra -g)
add_compile_options(${COMP_FLAGS})
find_package(GTest)
find_package(Threads)

set (CMAKE_CXX_COMPILER "/usr/bin/g++-10")

include_directories( placedata 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

set( HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/include/CSVParser.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Data.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/dataFormat.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/DataPoint.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/PlaceDataLib.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Placement.hpp
)

set( SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/CSVParser.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Data.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/DataPoint.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/PlaceDataLib.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Placement.cpp
)

add_library( placedata ${HEADERS} ${SOURCES} )
target_link_libraries( placedata )

set( TEST_SRCS
    tests/testDataPoint.cpp
    tests/testPlacement.cpp
    tests/tests.cpp
)

include_directories( placedatatests 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_executable( placedatatests EXCLUDE_FROM_ALL ${TEST_SRCS} )
target_link_libraries( placedatatests
    Threads::Threads
    placedata
    gtest
    gtest_main
)