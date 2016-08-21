//Given two numbers represented as strings, return multiplication of the numbers as a string.
//Note: The numbers can be arbitrarily large and are non-negative.
//Converting the input string to integer is NOT allowed.
//You should NOT use internal library such as BigInteger.

#include "all_header.h"

class Solution {
public:
    string add(string num1, string num2) {
        int len1 = num1.length(), len2 = num2.length();
        int i = len1 - 1, j = len2 - 1;
        int carry = 0;
        string res;
        while (i >= 0 && j >= 0) {
            int digit1 = num1[i] - '0', digit2 = num2[j] - '0';
            int sum = digit1 + digit2 + carry;
            carry = sum / 10;
            int digit = sum % 10;
            res = string(1, digit + '0') + res;
            --i, --j;
        }
        while (i >= 0) {
            int digit1 = num1[i] - '0';
            int sum = digit1 + carry;
            carry = sum / 10;
            int digit = sum % 10;
            res = string(1, digit + '0') + res;
            --i;
        }
        while (j >= 0) {
            int digit2 = num2[j] - '0';
            int sum = digit2 + carry;
            carry = sum / 10;
            int digit = sum % 10;
            res = string(1, digit + '0') + res;
            --j;
        }
        if (carry != 0) {
            res = string(1, carry + '0') + res;
        }
        return res;
    }

    string multiply_one(string num, char one) {
        int length = num.length();
        int i = length - 1;
        int digit2 = one - '0';
        int carry = 0;
        string res;
        while (i >= 0) {
            int digit1 = num[i] - '0';
            int product = digit1 * digit2 + carry;
            carry = product / 10;
            int digit = product % 10;
            res = string(1, digit + '0') + res;
            --i;
        }
        if (carry > 0) {
            res = string(1, carry + '0') + res;
        }
        return res;
    }

    string multiply(string num1, string num2) {
        if (num1.length() < num2.length()) {
            return multiply(num2, num1);
        }
        if (num1 == "0" || num2 == "0")
        {
            return "0";
        }
        int length = num2.size();
        string res = "0";
        for (int i = length - 1; i >= 0; i--) {
            char digit = num2[i];
            string num_temp = num1 + string(length - 1 - i, '0');
            string partial_result = multiply_one(num_temp, digit);
            res = add(res, partial_result);
        }
        return res;
    }
};