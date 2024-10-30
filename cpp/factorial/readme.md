C++ exercises: factorial
=========================

Simple factorial excercise.
Practice: factorial algorithm in c++, google test, cmake, git submodules

------------------
What is factorial?
------------------

The product of all positive integers less than or equal to n.

n! = n * (n-1) * (n-2) * (n-3) * ... * 1 = n * (n-1)!
0! = 1

Example:
4! = 4 * 3! = 4 * 3 * 2 * 1 = 24

------------------
Build instructions
------------------

1. Clone excercises git repository

2. Enter factorial directory
        $ cd cpp/factorial

3. Make build directory
        $ mkdir build

4. Enter build directory
        $ cd build

5. Run CMake to generate proper Makefiles:
        $ cmake ..

6. Run make
        $ make
