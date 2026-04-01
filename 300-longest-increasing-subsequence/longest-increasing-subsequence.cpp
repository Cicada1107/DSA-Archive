// nlog n approach - even more optimized - just removing the if condition by using lower_bound

#define ll long long

class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        int n = a.size();
        vector<int> dp(n+1, INT_MAX);
        dp[0] = INT_MIN;
        for(int i=0; i<n; i++){
            int l = lower_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
            dp[l] = a[i];
        }

        //debug
        // for(auto &it:dp) cout<<it<<" ";

        

        int ans = 0;
        for(int l=0; l<n+1; l++){
            if(dp[l] == INT_MAX) continue;
            if(dp[ans] < dp[l]){
                ans = l;
            }
        }

        return ans;
    }
};