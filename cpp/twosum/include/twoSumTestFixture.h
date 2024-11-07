// Two Sum excercise
// Copyright (C) 2024 by Piotr Kmiecik
// E-mail: info@aserio.pl

#ifndef _TWOSUMTESTFIXTURE_H_
#define _TWOSUMTESTFIXTURE_H_

#include <algorithm>
#include <vector>
#include <ostream>
#include <gtest/gtest.h>

#include <twoSum.h>

namespace twoSumTest {
        
struct params
{
        std::vector<int> nums;
        int target;
        std::vector<int> expected_result;

        friend void PrintTo(const params& p, std::ostream* os);
};

class fixture : public testing::Test,
                public testing::WithParamInterface<twoSumTest::params>
{
public:
        fixture();
protected:
        std::unique_ptr<twoSum> m_twoSum;
};

}; // twoSumTest

#endif // _TWOSUMTESTFIXTURE_H_
