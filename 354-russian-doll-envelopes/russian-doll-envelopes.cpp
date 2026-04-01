class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& a) {
        int n = a.size();
        sort(a.begin(), a.end(), [](vector<int> &a, vector<int> &b){
            if(a[0] == b[0]) return a[1] > b[1];
            else return a[0] < b[0];
        });

        vector<int> dp(n+1, INT_MAX);
        dp[0] = INT_MIN;
        for(int i=0; i<n; i++){
            int l = lower_bound(dp.begin(), dp.end(), a[i][1]) - dp.begin();
            dp[l] = a[i][1];
        }

        int ans = 0;
        for(int l=0; l<=n; l++){
            if(dp[l] == INT_MAX) continue;
            if(dp[l] > dp[ans]){
                ans = l;
            }
        }

        return ans;
    }
};