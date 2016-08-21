//Given an unsorted integer array, find the first missing positive integer.
//For example,
//        Given [1,2,0] return 3,
//and [3,4,-1,1] return 2.
//Your algorithm should run in O(n) time and uses constant space.
//Subscribe to see which companies asked this question

#include "all_header.h"

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int missing_num = 1;
        int length = (int)nums.size();
        int i = 0;
        while (i < length)
        {
            if (nums[i] != i + 1 && nums[i] >= 0 && nums[i] < length && nums[nums[i]-1] != nums[i])
            {
                swap(nums[i], nums[nums[i]-1]);
            }
            else
            {
                i++;
            }
        }

        for (i = 0; i < length; i++) {
            if (nums[i] != i+1)
            {
                break;
            }
        }
        return i + 1;
    }
};