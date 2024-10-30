// Factorial excercise
// Copyright (C) 2024 by Piotr Kmiecik

#include "factorialTestFixture.h"

factorialTestFixture::factorialTestFixture()
{
        m_factorial = std::make_unique<factorial>();
}

TEST_P (factorialTestFixture, factorialTest)
{
        auto param = GetParam();
        EXPECT_EQ(param.expected_result, m_factorial->getRecursive(param.value));
        EXPECT_EQ(param.expected_result, m_factorial->getIterative(param.value));
}
