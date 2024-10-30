// Factorial excercise
// Copyright (C) 2024 by Piotr Kmiecik

#include <iostream>

#include "factorialTestFixture.h"

INSTANTIATE_TEST_SUITE_P (Default, factorialTestFixture,
        testing::Values (
                factorialTestParams {0,1},
                factorialTestParams {1,1},
                factorialTestParams {2,2},
                factorialTestParams {3,6},
                factorialTestParams {4,24},
                factorialTestParams {5,120},
                factorialTestParams {9,362880}
        )
);

int main (int argc, char* argv[])
{
        std::cout << "Executing factorial excercise...\n" << std::endl;

        testing::InitGoogleTest(&argc, argv);
        return RUN_ALL_TESTS();
}
