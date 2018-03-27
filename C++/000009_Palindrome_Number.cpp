//
// Created by lmb on 2016/2/22.
// 1
//

//Determine whether an integer is a palindrome. Do this without extra space.

#include "all_header.h"

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        } else if (x == 0) {
            return true;
        }
        int y = 0, temp = x;
        while (temp != 0) {
            y *= 10;
            y += (temp%10);
            temp /= 10;
        }
        return (x == y);
    }
};