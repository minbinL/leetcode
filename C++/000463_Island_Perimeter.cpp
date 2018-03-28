//You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water. Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells). The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.
//
//Example:
//[[0,1,0,0],
//[1,1,1,0],
//[0,1,0,0],
//[1,1,0,0]]
//Answer: 16


#include "all_header.h"

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int l = grid.size();
        if (l == 0) {
            return 0;
        }
        int w = grid[0].size();
        int perimeter = 0;
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < w; j++) {
                if (grid[i][j] == 1) {
                    if (i + 1 < l && grid[i+1][j] == 0 || i + 1 >= l) {
                        perimeter += 1;
                    }
                    if (i - 1 >= 0 && grid[i-1][j] == 0 || i - 1 < 0) {
                        perimeter += 1;
                    }
                    if (j + 1 < w && grid[i][j+1] == 0 || j + 1 >= w) {
                        perimeter += 1;
                    }
                    if (j - 1 >= 0 && grid[i][j-1] == 0 || j - 1 < 0) {
                        perimeter += 1;
                    }
                }
            }
        }
        return perimeter;
    }
};