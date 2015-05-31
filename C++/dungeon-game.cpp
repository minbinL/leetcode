class Solution {
public:
    int calculateMinimumHP(vector<vector<int> > &dungeon) {
        int m = dungeon.size();
	if (m == 0) return -1;
	int n = dungeon[0].size();
        vector <vector<int> > dp (m, vector<int> (n, 1));
	for (int i = n-1; i >= 0; i--)
            for (int j = m-1; j >=0; j--) {
		if (i == n-1 && j == m-1) dp[i][j] = max(0-dungeon[i][j], 0);
		else if (i == n-1) dp[i][j] = max(dp[i][j+1]-dungeon[i][j], 0);
		else if (j == m-1) dp[i][j] = max(dp[i+1][j]-dungeon[i][j], 0);
		else dp[i][j] = max(min(dp[i+1][j]-dungeon[i][j], dp[i][j+1]-dungeon[i][j]), 0);
	}
        return dungeon[0][0] + 1;
    }
};
