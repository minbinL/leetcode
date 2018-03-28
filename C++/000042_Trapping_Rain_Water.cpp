// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
// For example, Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

#include "all_header.h"

class Solution {
public:
    int trap(vector<int>& height) {
        int length = height.size();
        if (length < 3)
        {
            return 0;
        }
        int capacity = 0;
        int first_height = max(height[0], height[length-1]), second_height = min(height[0], height[length-1]);
        int left =0, right = length - 1;
        while (right > left)
        {
            if (height[left] > height[right])
            {
                capacity += (second_height - height[right]);
                --right;
                second_height = max(height[right], second_height);
            }
            else
            {
                capacity += (second_height - height[left]);
                ++left;
                second_height = max(height[left], second_height);
            }
            if (first_height < second_height)
            {
                first_height ^= second_height;
                second_height ^= first_height;
                first_height ^= second_height;
            }
        }
        return capacity;
    }
};