class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int> (amount+1, INT_MAX));

        dp[0][0] = 0;
        for(int i=1; i<=n; i++){
            for(int s=0; s<=amount; s++){
                if(s == 0) dp[i][s] = 0;
                
                if(dp[i-1][s] != INT_MAX) dp[i][s] = dp[i-1][s];
                
                if(s>=coins[i-1] && dp[i][s-coins[i-1]] != INT_MAX){
                    dp[i][s] = min(1+dp[i][s-coins[i-1]], dp[i][s]);
                }
            }
        }

        return dp[n][amount] == INT_MAX ? -1 : dp[n][amount];
    }
};