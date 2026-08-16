#define ll long long
const ll min_val = -1e9;

class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        vector<vector<ll>> dp(n, vector<ll> (2, min_val));

        dp[0][0] = arr[0];
        
        for(int i=1; i<n; i++){
            dp[i][0] = max(dp[i-1][0]+arr[i] , static_cast<ll>(arr[i]));
        }

        for(int i=1; i<n; i++){
            if(dp[i-1][1] != min_val) dp[i][1] = dp[i-1][1]+arr[i];
            dp[i][1] = max(dp[i][1], (ll)arr[i]);
            if(dp[i-1][0] != min_val) dp[i][1] = max(dp[i][1], dp[i-1][0]);
        }


        ll ans = min_val;
        for(int i=0; i<n; i++){
            for(int j=0; j<2; j++){
                ans = max(ans, dp[i][j]);
            }
        }

        return ans;
    }
};