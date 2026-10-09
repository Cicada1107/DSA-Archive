#define ll long long
const ll INV = LLONG_MIN/4;

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<vector<ll>>> dp(n, vector<vector<ll>> (2, vector<ll> (2, INV)));

        dp[0][0][0] = nums[0];
        for(int i=1; i<n; i++){
            // case 1: d = 0
                // sub case 1: p = 0
                dp[i][0][0] = max(
                    (ll)nums[i],
                    dp[i-1][1][0] == INV ? INV : dp[i-1][1][0] + nums[i]
                );

                // sub case 2: p = 1
                // Note that we won't consider starting a new array here, because a single element would mean odd retained number of elements hence, p = 0, not 1.
                if(dp[i-1][0][0] != INV) {
                    dp[i][1][0] = max(dp[i][1][0], dp[i-1][0][0] - nums[i]);
                };

            // case 2: d = 1
                // sub case 1: p = 0
                dp[i][0][1] = max(
                    dp[i-1][0][0],
                    dp[i-1][1][1] == INV ? INV : dp[i-1][1][1] + nums[i]
                );

                // sub case 2: p = 1
                dp[i][1][1] = max(
                    dp[i-1][1][0],
                    dp[i-1][0][1] == INV ? INV : dp[i-1][0][1] - nums[i]
                );
        }

        ll ans = LLONG_MIN;
        for(auto it: dp){
            for(auto it2: it){
                for(auto it3: it2){
                    ans = max(it3, ans);
                }
            }
        }
        return ans;
    }
};