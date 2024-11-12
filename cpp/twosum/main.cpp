// Two Sum excercise
// Copyright (C) 2024 by Piotr Kmiecik
// E-mail: info@aserio.pl

#include <iostream>
#include <vector>

#include <twoSumTestFixture.h>

namespace twoSumTest {

INSTANTIATE_TEST_SUITE_P (Default, fixture,
        testing::Values(
                params {{2,7,11,15},9,{0,1}},
                params {{3,2,4},6,{1,2}},
                params {{3,3},6,{0,1}}
        )
);
}; // twoSumTest

int main (int argc, char* argv[]) 
{
        std::cout << "Executing Two Sum excercise..." << std::endl;
        testing::InitGoogleTest(&argc, argv);        
        return RUN_ALL_TESTS();
}
