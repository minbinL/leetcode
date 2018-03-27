//
// Created by lmb on 2016/2/22.
// 1
//

//Write a function to find the longest common prefix string amongst an array of strings.

#include "all_header.h"

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int len = strs.size();
        if (len == 0) {
            return 0;
        }
        int minlen = INT_MAX;
        for (int i = 0; i < len; i++) {
            minlen = min(minlen, (int)strs[i].length());
        }
        int i;
        for (i = 0; i < minlen; i++) {
            int flag = false;
            for(int j = 1; j < len; j++) {
                if (strs[j][i] != strs[j-1][i] ) {
                    flag = true;
                    break;
                }
            }
            if (flag) {
                break;
            }
        }

        string longestPrefix = strs[0].substr(0, i);
        return longestPrefix;
    }
};