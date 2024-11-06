// Two Sum excercise
// Copyright (C) 2024 by Piotr Kmiecik
// E-mail: info@aserio.pl

#include <twoSumTestFixture.h>

twoSumTestFixture::twoSumTestFixture()
{
        m_twoSum = std::make_unique<twoSum>();
}

TEST_P (twoSumTestFixture, testTwoSum)
{
        auto param = GetParam();
        EXPECT_EQ (param.expected_result, m_twoSum->bruteForce(param.nums, param.target));
        EXPECT_EQ (param.expected_result, m_twoSum->hash(param.nums, param.target));
}
