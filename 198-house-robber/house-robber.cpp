class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, 0);

        for(int i=1; i<=n; i++){
            int pick = 0, notPick = 0;
            if(i>=2) pick =  dp[i-2]+nums[i-1];
            else if(i==1) pick = nums[i-1];
            notPick = dp[i-1];
            dp[i] = max(pick, notPick);
        }
        return dp[n];
    }
};