//
// Created by lmb on 2016/2/22.
// 1
//

// Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0?
// Find all unique triplets in the array which gives the sum of zero.
// Note:
// Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
// The solution set must not contain duplicate triplets.
// For example, given array S = {-1 0 1 2 -1 -4},
//
// A solution set is:
// (-1, 0, 1)
// (-1, -1, 2)

#include "all_header.h"

// Time: O(n^2)
// Space: O(n)

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>> res;
        if (len < 3) {
            return res;
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < len; i++) {
            if (i != 0 && nums[i] == nums[i-1]) {
                continue;
            }
            int target = 0 - nums[i];
            int left = i + 1, right = len - 1;
            while (right > left) {
                int sum = nums[left] + nums[right];
                if (sum == target) {
                    vector<int> temp = {nums[i], nums[left], nums[right]};
                    res.push_back(temp);
                    right -= 1, left += 1;
                    while (nums[left] == nums[left-1]) {
                        left += 1;
                    }
                    while (nums[right] == nums[right+1]) {
                        right -= 1;
                    }
                } else if (sum > target) {
                    right -= 1;
                } else {
                    left += 1;
                }
            }
        }
        return res;
    }
};