// 1st revision attempt
#define ll long long

class Solution {
public:
    int candy(vector<int>& ratings) {
        ll n = ratings.size();
        vector<ll> ans(n, 1);
        
        // left
        for(int i=1; i<n; i++){
            if(ratings[i] > ratings[i-1]){
                ans[i] = ans[i-1]+1;
            }
        }
        
        //debug
        // for(auto &it: ans) cout<<it<<" ";
        // cout<<endl;

        // right
        for(int i=n-2; i>=0; i--){
            if(ratings[i] > ratings[i+1]){
                ans[i] = max((ll)ans[i+1]+1, ans[i]);
            }
        }

        //debug
        // for(auto &it: ans) cout<<it<<" ";
        // cout<<endl;

        return accumulate(ans.begin(), ans.end(), 0);
    }
};