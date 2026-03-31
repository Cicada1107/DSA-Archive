class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        // dp[i][d] = Length of longest Arithmetic Subsequence with difference 'd' ending on the 'i'th index in nums
        
        vector<unordered_map<int, int>> dp(n);
        int ans = 2;
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                int d = nums[i] - nums[j];
                dp[i][d] = max(dp[i][d], 1+(dp[j].count(d) ? dp[j][d] : 1));
                ans = max(ans, dp[i][d]);
            }
        }

        return ans;
    }
};