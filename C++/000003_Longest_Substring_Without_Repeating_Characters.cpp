//
// Created by lmb on 2016/2/22.
// 1
//

//Given a string, find the length of the longest substring without repeating characters. For example,
// the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3.
// For "bbbbb" the longest substring is "b", with the length of 1.
#include "all_header.h"

// Time: O(n)
// Space: O(n)

// hash table solution
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        if (len == 0) {
            return 0;
        }
        vector<int> hashtable(256, -1);
        int pre = 0, cur = 0;
        int maximumlen = 1;
        while (cur != len) {
            if (hashtable[s[cur]] != -1) {
                maximumlen = max(cur - pre, maximumlen);
                int destination = hashtable[s[cur]] + 1;
                while (pre != destination) {
                    hashtable[s[pre]] = -1;
                    pre += 1;
                }
            }
            hashtable[s[cur]] = cur;
            cur += 1;
        }
        maximumlen = max(maximumlen, cur - pre);
        return maximumlen;
    }
};