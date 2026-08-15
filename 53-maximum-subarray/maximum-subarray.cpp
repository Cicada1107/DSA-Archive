#define ll long long
const ll min_val = -1e9;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();

        vector<ll> dp(n, min_val);
        dp[0] = nums[0];
        for(int i=1; i<n; i++){
            dp[i] = max((ll)nums[i], dp[i-1]+nums[i]);
        }

        return (int)*max_element(dp.begin(), dp.end());
    }
};