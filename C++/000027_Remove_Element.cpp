//
// Created by lmb on 2016/2/23.
// 1
//

// Given an array and a value, remove all instances of that value in place and return the new length.
// The order of elements can be changed. It doesn't matter what you leave beyond the new length.

#include "all_header.h"

// Time: O(n)
// Space: O(1)

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
        if (len == 0) {
            return 0;
        }
        int i = -1, j = 0;
        while (j != len) {
            if (nums[j] != val) {
                i++;
                swap(nums[i], nums[j]);
            }
            j++;
        }
        return i + 1;
    }
};