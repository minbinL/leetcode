//
// Created by lmb on 2016/2/23.
// 1
//

// Implement strStr().
// Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

#include "all_header.h"

// Time: O(n^2)
// Space: O(1)

class Solution {
public:
    int strStr(string haystack, string needle) {
        int lenS = haystack.size(), lenT = needle.size();
        if (lenT == 0) {
            return 0;
        } else if (lenS ==0) {
            return -1;
        }
        int i = 0;
        while (i < lenS - lenT + 1) {
            int temp = i;
            int j;
            for (j = 0; j < lenT; j++) {
                if (haystack[i] != needle[j]) {
                    break;
                }
                i++;
            }
            if (j == lenT) {
                return temp;
            }
            i = temp + 1;
        }
        return -1;
    }
};