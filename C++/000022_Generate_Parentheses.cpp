//
// Created by lmb on 2016/2/22.
// 1
//

//Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
//For example, given n = 3, a solution set is:
//"((()))", "(()())", "(())()", "()(())", "()()()"

#include "all_header.h"

class Solution {
private:
    void generateParenthesisHelper (int left, int right, string temp) {
        if (left == 0 && right == 0) {
            res.push_back(temp);
            return;
        }
        string origin = temp;
        if (left != 0 ) {
            temp += string (1, '(');
            generateParenthesisHelper(left-1, right, temp);
            temp = origin;
        }
        if (left < right) {
            temp += string (1, ')');
            generateParenthesisHelper(left, right-1, temp);
            temp = origin;
        }
    }
    vector<string> res;
public:
    vector<string> generateParenthesis(int n) {
        res.clear();
        generateParenthesisHelper(n, n, "");
        return res;
    }
};