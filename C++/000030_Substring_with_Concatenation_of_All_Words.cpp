//
// Created by lmb on 2016/2/23.
// 1
//

// You are given a string, s, and a list of words, words, that are all of the same length.
// Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without
// any intervening characters.
// For example, given:
// s: "barfoothefoobarman"
// words: ["foo", "bar"]
// You should return the indices: [0,9].
// (order does not matter).

#include "all_header.h"

// Time: O(n^2)
// Space: O(n)

class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        int l_size = (int)L.size();
        if (l_size <= 0) {
            return vector<int>();
        }
        vector<int> result;
        map<string, int> word_count;
        int word_size = (int)L[0].size();
        int i, j;
        for (i = 0; i < l_size; ++i) {
            ++word_count[L[i]];
        }
        map<string, int> counting;
        for (i = 0; i <= (int)S.length() - (l_size * word_size); ++i) {
            counting.clear();

            for (j = 0; j < l_size; ++j) {
                string word = S.substr(i + j * word_size, word_size);

                if (word_count.find(word) != word_count.end()) {
                    ++counting[word];

                    if (counting[word] > word_count[word]) {
                        break;
                    }
                }
                else {
                    break;
                }
            }
            if (j == l_size) {
                result.push_back(i);
            }
        }
        return result;
    }
};