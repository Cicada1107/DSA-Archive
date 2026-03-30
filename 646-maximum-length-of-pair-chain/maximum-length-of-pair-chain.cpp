class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end());
        vector<int> dp(n, -1);
        dp[0] = 1;
        for(int i=1; i<n; i++){
            int maxi = 1;
            for(int j=0; j<i; j++){
                if(pairs[j][1] < pairs[i][0]) maxi = max(maxi, 1+dp[j]);
                else maxi = max(maxi, 1);
            }
            dp[i] = maxi;
        }

        //debug
        for(auto &it: dp) cout<<it<<" ";
        return *max_element(dp.begin(), dp.end());
    }
};