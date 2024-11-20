// converterTestFixture.cpp
// Copyright (c) 2024 by Piotr Kmiecik
// e-mail: info@aserio.pl

#include <converterTestFixture.h>

namespace converterTest {

fixture::fixture()
{
    m_converter = std::make_unique<converter<short>>();
}

TEST_P (fixture, testSamples)
{    
        auto param = GetParam();
        EXPECT_TRUE (param.binary == m_converter->toBinary(param.numeric));
        EXPECT_EQ (param.numeric, m_converter->fromBinary(param.binary));
}

}; // converterTest
