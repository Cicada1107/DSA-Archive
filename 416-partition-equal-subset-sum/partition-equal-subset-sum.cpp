#define ll long long

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        ll t=accumulate(nums.begin(), nums.end(), 0LL);

        if(t&1) return false;

        t/=2;
        
        int n = nums.size();
        vector<vector<bool>> dp(n+1, vector<bool> (t+1, 0LL));
        
        for(int i=0; i<=n; i++){
            dp[i][0] = 1;
        }

        for(int i=1; i<=n; i++){
            for(int s=1; s<=t; s++){
                dp[i][s] = dp[i-1][s];
                if(s-nums[i-1] >= 0) dp[i][s] = dp[i][s] || dp[i-1][s-nums[i-1]];
            }
        }

        return dp[n][t];
    }
};