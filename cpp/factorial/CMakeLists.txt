# Factorial excercise
# Copyright (C) 2024 by Piotr Kmiecik

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
    factorial.h
    factorialTestFixture.h

    main.cpp
    factorial.cpp
    factorialTestFixture.cpp
)

add_subdirectory(external/googletest)
include(GoogleTest)
gtest_discover_tests(main)

target_link_libraries(main
    PRIVATE GTest::gtest_main
)
