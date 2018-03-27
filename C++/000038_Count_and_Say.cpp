//
// Created by lmb on 2016/2/23.
// 1
//

// The count-and-say sequence is the sequence of integers beginning as follows:
// 1, 11, 21, 1211, 111221, ...
// 1 is read off as "one 1" or 11.
// 11 is read off as "two 1s" or 21.
// 21 is read off as "one 2, then one 1" or 1211.
// Given an integer n, generate the nth sequence.
// Note: The sequence of integers will be represented as a string.

#include "all_header.h"

class Solution {
public:
    string countAndSay(int n) {
        if (n <= 0) {
            return 0;
        } else if (n == 1) {
            return string(1, '1');
        }
        int count = n;
        string s = "1";
        while (count != 1) {
            count -= 1;
            int cnt = 1, record = s[0] - '0';
            string temp;
            for (int i = 1; i < s.length(); i++) {
                if (s[i]-'0' != record) {
                    temp += to_string(cnt);
                    temp += string(1, (char)(record + '0'));
                    record = s[i]-'0', cnt = 1;
                } else {
                    cnt++;
                }
            }
            temp += to_string(cnt);
            temp += string(1, (char)(record + '0'));
            s = temp;
        }
        return s;
    }
};