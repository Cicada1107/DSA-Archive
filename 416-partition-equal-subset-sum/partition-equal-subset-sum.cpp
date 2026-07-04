#define ll long long

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        ll sum = accumulate(nums.begin(), nums.end(), 0LL);
        if(sum&1) return false;
        sum /= 2;
        vector<vector<bool>> dp(n+1, vector<bool>(sum+1, false));

        // for(int s=0; s<=sum; s++){
        //     dp[0][s] = false;
        // }
        for(int i=0; i<=n; i++){
            dp[i][0] = true;
        }

        for(int i=1; i<=n; i++){
            for(ll s=1; s<=sum; s++){
                dp[i][s] = dp[i-1][s];
                if(s >= nums[i-1]) dp[i][s] = dp[i][s] || (dp[i-1][s-nums[i-1]]);
            }
        }

        bool ans = false;
        return dp[n][sum];
    }
};