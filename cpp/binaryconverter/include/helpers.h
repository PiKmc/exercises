// helpers.h
// Copyright (c) 2024 by Piotr Kmiecik
// e-mail: info@aserio.pl

#ifndef _HELPERS_H_
#define _HELPERS_H_

#include <string>
#include <algorithm>

inline bool isBinary(const std::string &s)
{        
        return !std::any_of(s.begin(), s.end(), [](auto const elem)
                                {return ((elem != '1') && (elem != '0'));});
}

#endif // _HELPERS_H_
