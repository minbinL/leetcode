//
// Created by lmb on 2016/2/22.
// 1
//

//The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
//P   A   H   N
//A P L S I I G
//Y   I   R
//And then read line by line: "PAHNAPLSIIGYIR"
//Write the code that will take a string and make this conversion given a number of rows:
//string convert(string text, int nRows);
//convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

#include "all_header.h"


class Solution {
public:
    string convert(string s, int numRows) {
        string res;
        if (s.length() <= numRows || numRows == 1) return s;
        for (int i = 0; i < numRows; i++) {
            if (i == numRows-1 || i == 0) {
                for (int j = i; j < s.length(); j += 2 * (numRows-1) ) {
                    res += string(1, s[j]);
                }
            }
            else {
                bool turn = true;
                for (int j = i; j < s.length(); )
                {
                    res += string(1, s[j]);
                    if (turn) {
                        j += 2*(numRows-1-i);
                    }
                    else {
                        j += (2*(numRows-1) - 2*(numRows-1-i));
                    }
                    turn = !turn;
                }
            }
        }
        return res;
    }
};