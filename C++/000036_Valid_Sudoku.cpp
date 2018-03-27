//
// Created by lmb on 2016/2/23.
// 1
//

// Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
// The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

// Note:
// A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.

#include "all_header.h"

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<int> > row(9, unordered_set<int>());
        vector<unordered_set<int> > col(9, unordered_set<int>());
        vector<unordered_set<int> > box(9, unordered_set<int>());
        for (int i = 0; i < board.size(); ++i)
            for (int j = 0; j < board.size(); j++) {
                if (board[i][j] != '.') {
                    if (!row[i].insert(board[i][j]).second) {
                        return false;
                    }
                    if (!col[j].insert(board[i][j]).second) {
                        return false;
                    }
                    if (!box[(i/3)*3 + j/3].insert(board[i][j]).second) {
                        return false;
                    }
                }
            }
        return true;
    }
};