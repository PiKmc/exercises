# Two Sum excercise
# Copyright (C) 2024 by Piotr Kmiecik
# E-mail: info@aserio.pl

cmake_minimum_required (VERSION 3.5)

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_C_COMPILER "gcc")
set (CMAKE_CXX_COMPILER "g++")
set (CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(main)
set (APP_EXE main)

include(submodules.cmake)

add_executable(main
        main.cpp
        twoSum.cpp
        twoSumTestFixture.cpp
)

target_include_directories(main PUBLIC BEFORE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_subdirectory(external/googletest)
include(GoogleTest)
gtest_discover_tests(main)

target_link_libraries(main
        PRIVATE GTest::gtest_main
)
