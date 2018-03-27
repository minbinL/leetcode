//
// Created by lmb on 2016/2/23.
// 1
//

// Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
// If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
// The replacement must be in-place, do not allocate extra memory.
// Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
// 1,2,3 → 1,3,2
// 3,2,1 → 1,2,3
// 1,1,5 → 1,5,1

#include "all_header.h"

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        if (len <= 1) {
            return;
        }
        int cur = len - 1, pre = len - 2;
        while (pre >= 0) {
            if (nums[pre] < nums[cur]) {
                break;
            }
            pre--, cur--;
        }
        if (pre == -1) {
            sort(nums.begin(), nums.end());
            return;
        }
        int idx = len - 1;
        while (nums[pre] >= nums[idx]) {
            idx--;
        }
        swap (nums[pre], nums[idx]);
        reverse(nums.begin() + cur, nums.end());
    }
};