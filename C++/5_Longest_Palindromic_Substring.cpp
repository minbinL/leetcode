//
// Created by lmb on 2016/2/22.
// 1
//

// Given a string S, find the longest palindromic substring in S.
// You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
#include "all_header.h"

// Time: O(n^2)
// Space: O(1)

class Solution {
    vector<int> extendPalindrome (string s, int left, int right) {
        vector<int> res;
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left -= 1, right += 1;
        }
        if ( (s[left] != s[right]) || left < 0 || right >= s.length()) {
            left += 1, right -= 1;
        }
        res.push_back(left);
        res.push_back(right);
        return res;
    }
public:
    string longestPalindrome(string s) {
        int len = s.length();
        if (len <= 1) {
            return s;
        }
        int left = 0, right = 0;
        for (int i = 0; i < len; i++) {
            if (i < len - 1 && s[i] == s[i+1]) {
                vector<int> res = extendPalindrome(s, i, i+1);
                if (right - left < res[1] - res[0]) {
                    left = res[0];
                    right = res[1];
                }
            }
            vector<int> res = extendPalindrome(s, i, i);
            if (right - left < res[1] - res[0]) {
                left = res[0];
                right = res[1];
            }
        }
        return s.substr((unsigned int)left, (unsigned int)right - (unsigned int)left + 1);
    }
};


// Time: O(n^2)
// Space: O(n^2)

//DP solution


// Time: O(n^2)
// Space: O(n^2)

// Manacher solution