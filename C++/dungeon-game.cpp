class Solution {
public:
    int calculateMinimumHP(vector<vector<int> > &dungeon) {
        int m = dungeon.size();
	if (m == 0) return -1;
	int n = dungeon[0].size();
        vector
	for (int i = n-1; i >= 0; i--)
            for (int j = m-1; j >=0; j++) {
		if (i == n-1 && j == m-1) 
	}
        return dungeon[0][0] + 1;
    }
};