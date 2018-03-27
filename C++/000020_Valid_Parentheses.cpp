//
// Created by lmb on 2016/2/22.
// 1
//

// Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
// The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

#include "all_header.h"

class Solution {
public:
    bool isValid(string s) {
        if (s.length() == 0) {
            return true;
        }
        stack<char> stk;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                stk.push(s[i]);
            } else {
                if ( !stk.empty() && ((s[i] == ')'&& stk.top() == '(') ||
                                      (s[i] == ']'&& stk.top() == '[') ||
                                      (s[i] == '}'&& stk.top() == '{')) ) {
                    stk.pop();
                } else {
                    return false;
                }
            }
        }
        return stk.empty();
    }
};