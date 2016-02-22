//
// Created by lmb on 2016/2/23.
// 1
//

//Given a sorted array and a target value, return the index if the target is found. If not,
// return the index where it would be if it were inserted in order.
//You may assume no duplicates in the array.
//Here are few examples.
//[1,3,5,6], 5 → 2
//[1,3,5,6], 2 → 1
//[1,3,5,6], 7 → 4
//[1,3,5,6], 0 → 0

#include "all_header.h"

// Time: O(nlogn)
// Space: O(1)

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int len = nums.size();
        if (len == 0) {
            return 0;
        }
        int left = 0, right = len - 1;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                right = mid;
            } else {
                left = mid;
            }
        }
        if (nums[left] >= target ) {
            return left;
        } else if (nums[right] >= target) {
            return right;
        } else {
            return right + 1;
        }
    }
};