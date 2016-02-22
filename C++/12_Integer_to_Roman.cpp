//
// Created by lmb on 2016/2/22.
// 1
//

// Given an integer, convert it to a roman numeral.
// Input is guaranteed to be within the range from 1 to 3999.

#include "all_header.h"


class Solution {
public:
    string intToRoman(int num) {
        vector<pair<string, int> >  mp { {"M", 1000}, {"CM", 900}, {"D", 500}, {"CD", 400}, {"C", 100}, {"XC", 90},
                                         {"L", 50}, {"XL", 40}, {"X", 10}, {"IX", 9}, {"V", 5}, {"IV", 4}, {"I", 1} };
        string result;
        while (num) {
            for (auto p : mp) {
                if (num >= p.second) {
                    result += p.first, num -= p.second;
                    break;
                }
            }
        }
        return result;
    }
};