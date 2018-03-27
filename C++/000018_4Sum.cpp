//
// Created by lmb on 2016/2/22.
// 1
//

// Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target?
// Find all unique quadruplets in the array which gives the sum of target.
// Note:
// Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
// The solution set must not contain duplicate quadruplets.
// For example, given array S = {1 0 -1 0 -2 2}, and target = 0.
// A solution set is:
// (-1,  0, 0, 1)
// (-2, -1, 1, 2)
// (-2,  0, 0, 2)

#include "all_header.h"


// Time: O(n^3)
// Space: O(n)

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int len = nums.size();
        vector<vector<int>> res;
        if (len <= 3) {
            return res;
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < len; i++) {
            if (i != 0 && nums[i] == nums[i-1]) {
                continue;
            }
            int target2 = target - nums[i];
            for (int j = i + 1; j < len; j++) {
                if (j != i + 1 && nums[j] == nums[j-1]) {
                    continue;
                }
                int target3 = target2 - nums[j];
                int left = j + 1, right = len - 1;
                while (right > left) {
                    int sum = nums[right] + nums[left];
                    if (sum == target3) {
                        vector<int> temp = {nums[i], nums[j], nums[left], nums[right]};
                        res.push_back(temp);
                        left += 1, right -= 1;
                        while (left < right && nums[left] == nums[left-1]) {
                            left += 1;
                        }
                        while (left < right && nums[right] == nums[right+1]) {
                            right -= 1;
                        }
                    } else if (sum > target3) {
                        right -= 1;
                    } else {
                        left += 1;
                    }
                }
            }
        }
        return res;
    }
};
