//
// Created by lmb on 2016/2/22.
// 1
//

// Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target.
// Return the sum of the three integers. You may assume that each input would have exactly one solution.
// For example, given array S = {-1 2 1 -4}, and target = 1.
// The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

#include "all_header.h"

// Time: O(n^2)
// Space: O(n)

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int len = nums.size();
        if (len < 3) {
            return INT_MAX;
        }
        sort(nums.begin(), nums.end());
        long long closestRes = INT_MAX;
        for (int i = 0; i < len; i++) {
            if (i != 0 && nums[i] == nums[i-1]) {
                continue;
            }
            int target2 = target - nums[i];
            int left = i + 1, right = len - 1;
            while (right > left) {
                int sum = nums[left] + nums[right];
                if (abs(sum + nums[i] - target) < abs(closestRes - target)) {
                    closestRes = sum + nums[i];
                }
                if (sum == target2) {
                    return target;
                } else if (sum > target2) {
                    right -= 1;
                } else {
                    left += 1;
                }
            }
        }
        return closestRes;
    }
};