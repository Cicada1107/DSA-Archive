// nlog n approach

#define ll long long

class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        int n = a.size();
        vector<int> dp(n+1, INT_MAX);
        dp[0] = INT_MIN;
        for(int i=0; i<n; i++){
            for(int l=1; l<n+1; l++){
                if(dp[l-1] < a[i] && a[i] < dp[l]){
                    dp[l] = a[i];
                }
            }
        }

        

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