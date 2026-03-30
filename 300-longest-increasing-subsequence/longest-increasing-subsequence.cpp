class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = 1;
        for(int i=1; i<n; i++){
            int maxi = 1;
            for(int j=0; j<i; j++){
                if(nums[j] < nums[i]) maxi = max(maxi, 1+dp[j]);
                else maxi = max(maxi, 1);
            }
            dp[i] = maxi;
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};