//
// Created by lmb on 2016/2/22.
// 1
//

//There are two sorted arrays nums1 and nums2 of size m and n respectively.
// Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
#include "all_header.h"

// Time: O(logn)
// Space: O(1)

// binary search solution
class Solution {
private:
    double findKth (int *nums1, int len1, int *nums2, int len2, int k) {
        if (len1 == 0) {
            return nums2[k-1];
        }
        if (len2 == 0) {
            return nums1[k-1];
        }
        if (k == 1) {
            return min(nums1[0], nums2[0]);
        }
        int mid = k/2;
        if (mid > len1) {
            return findKth(nums1, len1, nums2 + mid, len2 - mid, k - mid);
        }
        if (mid > len2) {
            return findKth(nums1 + mid, len1 - mid, nums2, len2, k - mid);
        }

        if (nums1[mid-1] >= nums2[mid-1]) {
            return findKth(nums1, len1, nums2 + mid, len2 - mid, k - mid);
        } else {
            return findKth(nums1 + mid, len1 - mid, nums2, len2, k - mid);
        }
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size();
        if (len1 == 0 && len2 == 0) {
            return -1;
        }
        int len = len1 + len2;
        if ((len & 1) == 0) {
            return (findKth(&nums1[0], len1, &nums2[0], len2, len/2) + findKth(&nums1[0], len1, &nums2[0], len2, len/2+1)) / 2.0;
        } else {
            return findKth(&nums1[0], len1, &nums2[0], len2, len/2+1);
        }
    }
};