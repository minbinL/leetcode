//Implement wildcard pattern matching with support for '?' and '*'.
//
//'?' Matches any single character.
//'*' Matches any sequence of characters (including the empty sequence).
//
//The matching should cover the entire input string (not partial).
//
//The function prototype should be:
//bool isMatch(const char *s, const char *p)
//
//Some examples:
//isMatch("aa","a") → false
//isMatch("aa","aa") → true
//isMatch("aaa","aa") → false
//isMatch("aa", "*") → true
//isMatch("aa", "a*") → true
//isMatch("ab", "?*") → true
//isMatch("aab", "c*a*b") → false

#include "all_header.h"

class Solution {
public:
    bool isMatch(string s, string p) {
        int length1 = s.length(), length2 = p.length();
        if (length2 == 0 && length1 != 0) {
            return false;
        }
        if (length1 == 0) {
            for (int i = 0; i < length2; i++) {
                if (p[i] != '*') {
                    return false;
                }
            }
            return true;
        }
        int idx1 = 0, idx2 = 0;
        int star = -1, rs = -1;
        while (idx1 < length1) {
            if ((s[idx1] == p[idx2] || p[idx2] == '?') && idx2 < length2) {
                ++idx1, ++idx2;
            } else if (idx2 < length2 && p[idx2] == '*') {
                star = idx2;
                rs = idx1;
                idx2 += 1;
            } else if (star != -1) {
                idx2 = star;
                rs += 1;
                idx1 = rs;
            } else {
                return false;
            }
        }

        while (idx2 < length2 && p[idx2] == '*') {
            ++idx2;
        }

        return idx2 == length2;
    }
};