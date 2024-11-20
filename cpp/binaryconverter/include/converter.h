// converter.h
// Copyright (c) 2024 by Piotr Kmiecik
// e-mail: info@aserio.pl

#ifndef _CONVERTER_H_
#define _CONVERTER_H_

#include <stdexcept>
#include <string>
#include <iostream>
#include <type_traits>
#include <cassert>

#include <helpers.h>

#define assertm(exp, msg) assert(((void)msg, exp))

template <typename T>
class converter {
public:
        std::string toBinary(T val);
        T fromBinary(const std::string &val) const;
};

///////////////////////////////////////////////////////////////////////////////

template<typename T>
std::string converter<T>::toBinary(T val)
{
        static_assert(
                std::is_integral_v<T>,
                "Cannot convert non integral value."
        );

        std::string ret = "";
        constexpr T mask = 0x01;

        for (size_t i=0; i<(sizeof(val)*8);++i)
        {
                ret.insert(0,std::to_string(val&mask));
                val >>= 1;
        }
        return ret;
}

template<typename T>
T converter<T>::fromBinary(const std::string &val) const
{
        assertm(isBinary(val),
                "Non binary value"
        );
        assertm(((std::is_signed_v<T>) && (val.size() == sizeof(T)*8)),
                "Invalid number of bits"
        );

        T ret = 0;
        for(auto i = val.begin(); i != val.end(); ++i) {
                if (*i == '1')
                        ret |= 1;
                if (std::next(i,1) != val.end())
                        ret <<= 1;
        }
        return ret;
}

#endif // _CONVERTER_H_
