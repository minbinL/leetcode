//
// Created by lmb on 2016/2/22.
// 1
//

// Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai).
// n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).
// Find two lines, which together with x-axis forms a container, such that the container contains the most water.
// Note: You may not slant the container

#include "all_header.h"

// Time: O(n)
// Space: O(1)

class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = height.size();
        if (len <= 1) {
            return 0;
        }
        int left = 0, right = len - 1;
        int maxArea = 0;
        while (right > left) {
            if (height[right] > height[left]) {
                maxArea = max(maxArea, height[left] * (right - left));
                left++;
            } else {
                maxArea = max(maxArea, height[right] * (right - left));
                right--;
            }
        }
        return maxArea;
    }
};