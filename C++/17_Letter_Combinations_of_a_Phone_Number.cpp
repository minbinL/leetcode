//
// Created by lmb on 2016/2/22.
// 1
//

// Given a digit string, return all possible letter combinations that the number could represent.
// Input:Digit string "23"
// Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
// Note: Although the above answer is in lexicographical order, your answer could be in any order you want.

#include "all_header.h"

class Solution {
private:
    vector<string> result;
    void letterCombinations(string digits, int start, string mediState, map<char, vector<char> > &hashtable) {
        if (start == digits.length() ) {
            result.push_back(mediState);
            return;
        }
        int len = hashtable[digits[start]].size();
        for (int i = 0; i < len; i++) {
            string origin = mediState;
            mediState += string(1, hashtable[digits[start]][i]);
            letterCombinations(digits, start+1, mediState, hashtable);
            mediState = origin;
        }
    }
public:
    vector<string> letterCombinations (string digits) {
        result.clear();
        if (digits.length()==0) {
            return result;
        }
        map<char, vector<char> > hashtable;
        hashtable['2'] = vector<char>( {'a', 'b', 'c'} );
        hashtable['3'] = vector<char>( {'d', 'e', 'f'} );
        hashtable['4'] = vector<char>( {'g', 'h', 'i'} );
        hashtable['5'] = vector<char>( {'j', 'k', 'l'} );
        hashtable['6'] = vector<char>( {'m', 'n', 'o'} );
        hashtable['7'] = vector<char>( {'p', 'q', 'r', 's'} );
        hashtable['8'] = vector<char>( {'t', 'u', 'v'} );
        hashtable['9'] = vector<char>( {'w', 'x', 'y', 'z'} );
        letterCombinations(digits, 0, "", hashtable);
        return result;
    }
};