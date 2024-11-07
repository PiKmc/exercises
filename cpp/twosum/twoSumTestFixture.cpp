// Two Sum excercise
// Copyright (C) 2024 by Piotr Kmiecik
// E-mail: info@aserio.pl

#include <twoSumTestFixture.h>

namespace twoSumTest {

void PrintTo(const params& p, std::ostream* os)
{                
        *os << std::endl;
        *os << "\tNums:";
        std::for_each(p.nums.begin(), p.nums.end(),
                [&](const int& v) { *os << ' ' << v; });
        *os << std::endl;
        *os << "\tTarget: " << p.target << std::endl;
        *os << "\tExpected result:";
        std::for_each(p.expected_result.begin(), p.expected_result.end(),
                [&](const int& v) { *os << ' ' << v; });
}

fixture::fixture()
{
        m_twoSum = std::make_unique<twoSum>();
}

TEST_P (fixture, testSamples)
{
        auto param = GetParam();
        EXPECT_EQ (param.expected_result, m_twoSum->bruteForce(param.nums, param.target));
        EXPECT_EQ (param.expected_result, m_twoSum->hash(param.nums, param.target));
}

}; // twoSumTest
