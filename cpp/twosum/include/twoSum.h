// Two Sum excercise
// Copyright (C) 2024 by Piotr Kmiecik
// E-mail: info@aserio.pl

#ifndef _TWOSUM_H_
#define _TWOSUM_H_

#include <vector>

class twoSum {
public:
    std::vector<int> bruteForce(const std::vector<int>& nums, const int target) const;
    std::vector<int> hash(const std::vector<int>& nums, const int target) const;
};

#endif // _TWOSUM_H_
