#define ll long long

class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<ll>>> dp(m, (vector<vector<ll>> (n, vector<ll> (k+1, -1))));
        dp[0][0][0] = 0;
        vector<int> cost = {0, 1, 1}, score = {0, 1, 2};

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i == 0 && j == 0) continue;
                
                ll cell_cost = cost[grid[i][j]];
                ll cell_score = score[grid[i][j]];

                for(ll c=cell_cost; c<=k; c++){
                    ll prev_cost = c-cell_cost;
                    ll prev_best_score = -1;

                    if(i>0 && dp[i-1][j][prev_cost] != -1){
                        prev_best_score = max(prev_best_score, dp[i-1][j][prev_cost]);
                    }
                    if (j > 0 && dp[i][j - 1][prev_cost] != -1) {
                        prev_best_score = max(prev_best_score, dp[i][j - 1][prev_cost]);
                    }

                    if(prev_best_score != -1){
                        dp[i][j][c] = prev_best_score + cell_score;
                    }
                }
            }
        }

        return *max_element(dp[m-1][n-1].begin(), dp[m-1][n-1].end());
        
    }
};