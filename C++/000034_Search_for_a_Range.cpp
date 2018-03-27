//
// Created by lmb on 2016/2/23.
// 1
//

// Given a sorted array of integers, find the starting and ending position of a given target value.
// Your algorithm's runtime complexity must be in the order of O(log n).
// If the target is not found in the array, return [-1, -1].
// For example,
// Given [5, 7, 7, 8, 8, 10] and target value 8,
// return [3, 4].

#include "all_header.h"

// Time: O(nlogn)
// Space: O(1)

class Solution {
    vector<int> res;
    int findValue (vector<int> &nums, int target, bool isleft) {
        int len = nums.size();
        if (len == 0) {
            return -1;
        }
        int left = 0, right = len - 1;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                if (isleft) {
                    right = mid;
                } else {
                    left = mid;
                }
            } else if (nums[mid] > target) {
                right = mid;
            } else {
                left = mid;
            }
        }
        if (isleft && nums[left] == target) {
            return left;
        } else if (isleft && nums[right] == target){
            return right;
        } else if (nums[right] == target) {
            return right;
        } else if (nums[left] == target) {
            return left;
        }
        return -1;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        res.clear();
        int left = findValue(nums, target, true);
        int right = findValue(nums, target, false);
        res.push_back(left);
        res.push_back(right);
        return res;
    }
};