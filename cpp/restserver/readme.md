C++ exercises: REST server
======================

Description:

This is a rest server with the very basic API example generated by Python script 
and based on what's written in api.json file.

Written in c++, uses Boost and nlohmann json libraries.

------------------------
Usage
------------------------

Build and run server
Use curl to test the API listed in api.json e.g.:
```shell
 $ curl http://127.0.0.1:7654/one
```

------------------------
Build instructions linux
------------------------

Waring!

- Requires python3 installed on your system and placed into your path direcotry.
- Requires active internet connection in order to download required libraries automatically

1. Clone excercises git repository
```shell
        $ git clone https://github.com/PiKmc/exercises.git
```
2. Enter factorial directory
```shell
        $ cd cpp/restserver
```
3. Make build directory
```shell
        $ mkdir build
```
4. Enter build directory
```shell
        $ cd build
```
5. Run CMake to generate proper Makefiles:
```shell
        $ cmake ..
```
6. Run make
```shell   
        $ make
```
