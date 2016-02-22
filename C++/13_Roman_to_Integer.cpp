//
// Created by lmb on 2016/2/22.
// 1
//

// Given a roman numeral, convert it to an integer.
// Input is guaranteed to be within the range from 1 to 3999.

#include "all_header.h"

class Solution {
private:
    map<char, int> mp;
public:
    Solution() {
        pair<char, int> init_value[] =
                {
                        pair<char, int>('I', 1),
                        pair<char, int>('V', 5),
                        pair<char, int>('X', 10),
                        pair<char, int>('L', 50),
                        pair<char, int>('C', 100),
                        pair<char, int>('D', 500),
                        pair<char, int>('M', 1000)
                };
        for (int i = 0; i < sizeof(init_value)/8; ++i) {
            mp[init_value[i].first] = init_value[i].second;
        }
    }
    int romanToInt(string s) {
        int len = s.length();
        if (len == 0) {
            return -1;
        }
        int res = 0;
        for (int i = 0; i < len; i++) {
            if (i == 0) {
                res += mp[s[i]];
            } else {
                if (mp[s[i]] > mp[s[i-1]]) {
                    res = mp[s[i]] - 2 * mp[s[i-1]] + res;
                } else {
                    res += mp[s[i]];
                }
            }
        }
        return res;
    }
};