//
// Created by lmb on 2016/2/23.
// 1
//

// Given a sorted array, remove the duplicates in place such that each element appear only
// once and return the new length.
// Do not allocate extra space for another array, you must do this in place with constant memory.
// For example,
// Given input array nums = [1,1,2],
// Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
// It doesn't matter what you leave beyond the new length.

#include "all_header.h"

// Time: O(n)
// Space: O(1)

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if (len <= 1) {
            return len;
        }
        int i = -1, j = 0;
        while (j != len) {
            if (j == 0) {
                j++, i++;
            } else {
                if (nums[j] != nums[j-1]) {
                    i++;
                    nums[i] = nums[j];
                }
                j++;
            }
        }
        nums.erase(nums.begin() + i + 1, nums.end());
        return nums.size();
    }
};
