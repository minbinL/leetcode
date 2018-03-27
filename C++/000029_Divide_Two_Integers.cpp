//
// Created by lmb on 2016/2/23.
// 1
//

// Divide two integers without using multiplication, division and mod operator.
// If it is overflow, return MAX_INT.

#include "all_header.h"

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0) {
            return INT_MAX;
        }
        bool isminus = true;
        if ( (dividend < 0 && divisor < 0) || (dividend > 0 && divisor > 0) ) {
            isminus = false;
        }
        long long x = abs((long long) dividend), y = abs((long long) divisor);
        long long dim = 1;
        long long res = 0;
        while (x >= y) {
            long long temp = y;
            while (x > y) {
                y <<= 1;
                dim <<= 1;
            }
            if ( y > x) {
                y >>= 1;
                dim >>= 1;
            }
            x -= y;
            y = temp;
            res += dim;
            dim = 1;
        }
        if (isminus) {
            if ( -res < INT_MIN) {
                return INT_MAX;
            } else {
                return -res;
            }
        } else {
            if (res > INT_MAX) {
                return INT_MAX;
            } else {
                return res;
            }
        }
    }
};