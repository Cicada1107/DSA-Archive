#define ll long long

class Solution {
public:
    int findMaxVal(int n, vector<vector<int>>& restrictions, vector<int>& diff) {
        vector<ll> ans(n), l(n, INT_MAX), r(n, INT_MAX);
        ans[0] = 0; l[0] = 0; r[0] = 0;
        for(auto &it: restrictions){
            int ind = it[0], maxVal = it[1];
            ans[ind] = maxVal;
            l[ind] = maxVal;
            r[ind] = maxVal;
        }

        for(int i=0; i<n-1; i++){
            l[i+1] = min(l[i]+diff[i], l[i+1]);
        }

        // for(auto it: l) cout<<it<<" ";
        // cout<<endl;

        for(int i=n-2; i>=0; i--){
            r[i] = min(r[i+1]+diff[i], r[i]);
        }


        for(int i=0; i<n; i++){
            ans[i] = min(l[i], r[i]);
        }

        return *max_element(ans.begin(), ans.end());
    }
};