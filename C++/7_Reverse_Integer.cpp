//
// Created by lmb on 2016/2/22.
// 1
//

// Reverse digits of an integer.
// Example1: x = 123, return 321
// Example2: x = -123, return -321
#include "all_header.h"

class Solution {
public:
    int reverse(int x) {
        bool isminus = false;
        if (x < 0) {
            isminus = true;
        }
        long long xx = x;
        if (isminus) {
            xx = -xx;
        }
        long long temp = 0;
        while (xx != 0) {
            temp *= 10;
            temp += (xx%10);
            xx /= 10;
        }
        if (!isminus) {
            if ( temp > INT_MAX) {
                return 0;
            } else {
                return (int)temp;
            }
        } else {
            temp = -temp;
            if (temp < INT_MIN) {
                return 0;
            } else {
                return (int)temp;
            }
        }

    }
};