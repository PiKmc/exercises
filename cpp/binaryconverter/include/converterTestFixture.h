// converterTestFixture.h
// Copyright (c) 2024 by Piotr Kmiecik
// e-mail: info@aserio.pl

#ifndef _CONVERTERTESTFIXTURE_H_
#define _CONVERTERTESTFIXTURE_H_

#include <algorithm>
#include <string>
#include <gtest/gtest.h>

#include <converter.h>

namespace converterTest {

struct params 
{
        short numeric;
        std::string binary;
};

class fixture : public testing::Test,
                public testing::WithParamInterface<params>
{
public:
        fixture();
protected:
        std::unique_ptr<converter<short>> m_converter;
};

}; // converterTest

#endif // _CONVERTERTESTFIXTURE_H_
