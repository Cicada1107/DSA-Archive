// binary search

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        for(int i=0; i<n; i++){
            int maxi = 0;
            for(int j=0; j<i; j++){
                if(nums[j]>=nums[i]) continue;
                maxi = max(maxi, dp[j]);
            }
            dp[i] = 1+maxi;
        }

        return *max_element(dp.begin(), dp.end());
    }
};