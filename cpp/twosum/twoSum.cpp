// Two Sum excercise
// Copyright (C) 2024 by Piotr Kmiecik
// E-mail: info@aserio.pl

#include <unordered_map>

#include <twoSum.h>

std::vector<int> twoSum::bruteForce(const std::vector<int>& nums, const int target) const
{
        for (int i=0; i<nums.size(); ++i)
                for (int j=0;j<nums.size(); ++j)
                {
                        if ((nums[i] + nums[j] == target) && (i!=j))
                                return {i,j};
                }
        return {};
}

std::vector<int> twoSum::hash(const std::vector<int>& nums, const int target) const
{
        std::unordered_map<int,int> mp;
        for (int i=0; i<nums.size();++i)
                mp[nums[i]] = i;

        for (int i=0;i<nums.size();++i)
        {
                int tmp = target - nums[i];
                if ((mp.find(tmp) != mp.end()) && mp[tmp] != i)
                        return {i,mp[tmp]};
        }
        return{};
}
