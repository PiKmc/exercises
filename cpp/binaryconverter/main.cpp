// Binary converter excercise
// Copyright (C) 2024 by Piotr Kmiecik
// e-mail: info@aserio.pl

#include <iostream>

#include <converterTestFixture.h>
#include <sys/types.h>

namespace converterTest {

INSTANTIATE_TEST_SUITE_P (Default, fixture,
        testing::Values(
                params { 5,"0000000000000101"},
                params {-5,"1111111111111011"}
        )
);
}; // converterTest

int main (int argc, char* argv[])
{
        std::cout << "Executing binary converter excercise...\n" << std::endl;

        testing::InitGoogleTest(&argc, argv);
        return RUN_ALL_TESTS();
}
