// Factorial excercise
// Copyright (C) 2024 by Piotr Kmiecik

#ifndef _FACTORIALTESTFIXTURE_H_
#define _FACTORIALTESTFIXTURE_H_

#include <gtest/gtest.h>

#include "factorial.h"

struct factorialTestParams
{
        int value;
        int expected_result;
};

class factorialTestFixture : public testing::Test,
                             public testing::WithParamInterface<factorialTestParams>
{
public:
        factorialTestFixture();
protected:
        std::unique_ptr<factorial> m_factorial;
};

#endif // _FACTORIALTESTFIXTURE_H_
