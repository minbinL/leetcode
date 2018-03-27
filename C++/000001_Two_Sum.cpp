//
// Created by lmb on 2016/2/22.
// 1
//

//Given an array of integers, return indices of the two numbers such that they add up to a specific target.
//You may assume that each input would have exactly one solution.
//Example:
//        Given nums = [2, 7, 11, 15], target = 9,
//        Because nums[0] + nums[1] = 2 + 7 = 9,
//return [0, 1].
//UPDATE (2016/2/13):
//The return format had been changed to zero-based indices. Please read the above updated description carefully.
#include "all_header.h"

// Time: O(n)
// Space: O(n)

// hash table solution
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> unorderedMap;
        vector<int> result;
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            int numToFind = target - nums[i];
            if (unorderedMap.find(numToFind) != unorderedMap.end()) {
                result.push_back(unorderedMap[numToFind]);
                result.push_back(i);
                break;
            }
            else {
                unorderedMap[nums[i]] = i;
            }
        }
        return result;
    }

    void static test()
    {
        Solution *s = new Solution();
        vector<int> test_vec = vector<int> (10, 3);
        vector<int> result = s->twoSum(test_vec, 6);
        for (auto iter = result.begin(); iter != result.end(); ++iter)
        {
            cout << *iter << endl;
        }
    }
};
