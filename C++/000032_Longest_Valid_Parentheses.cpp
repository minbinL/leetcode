//
// Created by lmb on 2016/2/23.
// 1
//

// Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
// For "(()", the longest valid parentheses substring is "()", which has length = 2.
// Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.

#include "all_header.h"

// Time: O(n)
// Space: O(n)

class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.length();
        stack<int> stk;
        vector<bool> dp((unsigned long long)len, false);
        for (int i = 0; i < len; i++) {
            if (s[i] == '(') {
                stk.push(i);
            } else {
                if (!stk.empty()) {
                    int idx = stk.top();
                    stk.pop();
                    dp[idx] = true;
                    dp[i] = true;
                }
            }
        }
        int count = 0, pre = 0, cur = 0;
        while (cur != len) {
            if (dp[cur]) {
                cur++;
            } else{
                count = max(count, cur - pre);
                cur++;
                pre = cur;
            }
        }
        count = max(count, cur - pre);
        return count;
    }
};