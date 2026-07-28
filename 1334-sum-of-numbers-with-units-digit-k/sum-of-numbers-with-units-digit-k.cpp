// approach 1: DP (Coin change pattern)

class Solution {
public:
    int minimumNumbers(int num, int k) {

        vector<int> coins;
        for(int i=k; i<=num; i+=10){
            coins.push_back(i);
        }
        int n = coins.size();
        
        vector<vector<int>> dp(n+1, vector<int> (num+1, 0));

        for(int i=0; i<=num; i++){
            if(i == 0) continue;
            dp[0][i] = INT_MAX-1;
        }
        dp[0][0] = 0;

        for(int i=1; i<=n; i++){
            for(int s=1; s<=num; s++){
                dp[i][s] = dp[i-1][s];
                if(s >= coins[i-1]) dp[i][s] = min(dp[i][s], 1+dp[i][s-coins[i-1]]);
            }
        }

        return dp[n][num] == INT_MAX-1 ? -1 : dp[n][num];
    }
};