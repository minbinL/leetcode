//Given a 2D binary matrix filled with 0's and 1's, find the largest square containing all 1's and return its area.
//
//For example, given the following matrix:
//
//1 0 1 0 0
//1 0 1 1 1
//1 1 1 1 1
//1 0 0 1 0
//Return 4.

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
        vector<vector<int> > dp (2, vector<int> (matrix[0].size(), 1));
        int turn = 1;
        int res = 0;
        for (int i = 0; i < matrix.size(); ++i) {
        	turn = (turn + 1) % 2;
        	for (int j = 0; j < matrix[0].size(); ++j) {
        		if(i == 0 || j == 0) dp[turn][j] = matrix[i][j] - '0';
        		else {
        			int pre_turn = (turn + 1) % 2;
        			if (matrix[i][j] == '0') dp[turn][j] = 0;
					else dp[turn][j] = min(dp[pre_turn][j-1], min(dp[pre_turn][j], dp[turn][j-1])) + 1;
				}
				res = res>dp[turn][j]?res:dp[turn][j];
			}
		}
        return res * res;
    }
};
