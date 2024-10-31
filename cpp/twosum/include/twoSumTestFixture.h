// Two Sum excercise
// Copyright (C) 2024 by Piotr Kmiecik
// E-mail: info@aserio.pl

#ifndef _TWOSUMTESTFIXTURE_H_
#define _TWOSUMTESTFIXTURE_H_

#include <vector>
#include <gtest/gtest.h>

#include <twoSum.h>

struct twoSumTestParams
{
        std::vector<int> nums;
        int target;
        std::vector<int> expected_result;
};

class twoSumTestFixture : public testing::Test,
                          public testing::WithParamInterface<twoSumTestParams>
{
public:
        twoSumTestFixture();
protected:
        std::unique_ptr<twoSum> m_twoSum;
};

#endif // _TWOSUMTESTFIXTURE_H_
