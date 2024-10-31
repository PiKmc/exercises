// Two Sum excercise
// Copyright (C) 2024 by Piotr Kmiecik
// E-mail: info@aserio.pl

#include <twoSum.h>

std::vector<int> twoSum::bruteForce(std::vector<int>& nums, int target)
{
        for (int i=0; i<nums.size(); ++i)
                for (int j=0;j<nums.size(); ++j)
                {
                        if ((nums[i] + nums[j] == target) && (i!=j))
                                return {i,j};
                }
        return {};
}
