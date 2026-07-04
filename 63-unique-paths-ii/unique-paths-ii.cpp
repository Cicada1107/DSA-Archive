class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        if(grid[0][0] == 1) return 0;

        dp[0][0] = 1;
        for(int i=1; i<m; i++) dp[i][0] = (grid[i][0] == 0? dp[i-1][0] : 0);
        for(int i=1; i<n; i++) dp[0][i] = (grid[0][i] == 0? dp[0][i-1] : 0);

        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(grid[i][j] == 1) continue;
                if(grid[i-1][j] != 1) dp[i][j] += dp[i-1][j];
                if(grid[i][j-1] != 1) dp[i][j] += dp[i][j-1];
            }
        }

        return dp[m-1][n-1];
    }
};