# REST server excercise
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

set (CPM_SOURCE_CACHE  ${CMAKE_CURRENT_SOURCE_DIR}/external)

include(cmake/CPM.cmake)

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

set(BOOST_INCLUDE_LIBRARIES "asio; beast;")

CPMAddPackage(
  NAME Nlohmann_json
  VERSION 3.11.3
  URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz
  URL_HASH SHA256=d6c65aca6b1ed68e7a182f4757257b107ae403032760ed6ef121c9d55e81757d
  OPTIONS "JSON_ENABLE_CMAKE ON"
)

CPMAddPackage(
  NAME Boost
  VERSION 1.86.0
  URL https://archives.boost.io/release/1.86.0/source/boost_1_86_0.tar.gz
  URL_HASH SHA256=2575e74ffc3ef1cd0babac2c1ee8bdb5782a0ee672b1912da40e5b4b591ca01f  
  OPTIONS "BOOST_ENABLE_CMAKE ON"
)

add_executable(main
        handler.cpp
        connection.cpp
        server.cpp
        main.cpp
)

set (PY_CMD ${CMAKE_CURRENT_SOURCE_DIR}/script.py)

add_custom_command(
    TARGET main
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    PRE_BUILD 
    COMMAND python3 ${PY_CMD}
    COMMENT "Start Python generation"
)

target_compile_features(main PRIVATE cxx_std_17)

target_include_directories(main PUBLIC BEFORE        
        ${Boost_SOURCE_DIR}
        ${Nlohmann_json_SOURCE_DIR}/include
)
