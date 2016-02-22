//
// Created by lmb on 2016/2/22.
// 1
//

// Implement atoi to convert a string to an integer.
// Hint: Carefully consider all possible input cases. If you want a challenge,
// please do not see below and ask yourself what are the possible input cases.
// Notes: It is intended for this problem to be specified vaguely (ie, no given input specs).
// You are responsible to gather all the input requirements up front.

#include "all_header.h"

class Solution {
    int parse_char (string s, int &pos, string cset) {
        int res = 0, length = s.length();
        if (length > pos && cset.find(s[pos]) != -1) {
            res = 1;
            pos += 1;
        }
        return res;
    }
    void parse_space (string s, int &pos) {
        while (parse_char(s, pos, " "));
    }
public:
    int myAtoi(string str) {
        int pos = 0, len = str.length();
        parse_space(str, pos);
        if (pos >= len) {
            return 0;
        }
        bool isMinus = false;
        if (str[pos] == '-') {
            isMinus = true;
            pos += 1;
        } else if (str[pos] == '+') {
            pos += 1;
        }
        string res;
        for (int i = pos; i < len; i++) {
            if (str[i] >= '0' && str[i] <= '9') {
                res += string(1, str[i]);
            } else {
                break;
            }
        }
        if (res.length() > 10) {
            if (isMinus) {
                return INT_MIN;
            } else {
                return INT_MAX;
            }
        }
        long long temp = 0;
        for (int i = 0; i < res.length(); i++) {
            temp *= 10;
            temp += (res[i] - '0');
        }
        if (isMinus) {
            temp = -temp;
            if (temp < INT_MIN) {
                return INT_MIN;
            } else {
                return (int)temp;
            }
        } else {
            if (temp > INT_MAX){
                return INT_MAX;
            } else {
                return (int)temp;
            }
        }
    }
};