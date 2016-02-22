//
// Created by lmb on 2016/2/23.
// 1
//

// Write a program to solve a Sudoku puzzle by filling the empty cells.
// Empty cells are indicated by the character '.'.
// You may assume that there will be only one unique solution.

#include "all_header.h"

class Solution {
private:
    bool row[9][10];
    bool col[9][10];
    bool box[9][10];

    bool isValid (int i, int j, int val)
    {
        return (!row[i][val] && !col[j][val] && !box[(i/3)*3 + j/3][val]);
    }

    bool solveSudokuHelper (vector<vector<char>>& board, int i, int j) {
        while (i < 9 && j < 9 && board[i][j] != '.') {
            if (j < 8) {
                j++;
            } else {
                i = i + 1;
                j = 0;
            }
        }
        if (i == 9) {
            return true;
        }
        for (int k = 1; k <= 9; k++) {
            if (isValid(i, j, k)) {
                board[i][j] = (char)(k + '0');
                row[i][k] = true, col[j][k] = true, box[(i/3)*3 + j/3][k] = true;
                if (solveSudokuHelper(board, i, j)) {
                    return true;
                }
                row[i][k] = false, col[j][k] = false, box[(i/3)*3 + j/3][k] = false;
                board[i][j] = '.';
            }
        }
        return false;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                row[i][j] = false, col[i][j] = false, box[i][j] = false;
            }
        }
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0';
                    row[i][num] = true, col[j][num] = true, box[(i/3)*3 + j/3][num] = true;
                }
            }
        }
        solveSudokuHelper(board, 0, 0);
    }
};