#define ll long long

class Solution {
public:
    vector<int> lexSmallestNegatedPerm(int n, long long target) {
        ll s = (static_cast<ll>(n)*(n+1))/2;
        
        if((abs(target) > s) || ((s-target)&1)) return {};
        
        vector<bool> hash(n+1, false);
        ll x = (s - target)/2;
        for(ll i=n; i>0; i--){
            if(x>=i && x-i <= (i*(i-1))/2){
                x -= i;
                hash[i] = true;
            }
        }

        // debug
        // for(int i=0; i<n; i++){
        //     if(hash[i]) cout<<i<<" ";
        // }
        // cout<<endl;

        vector<int> ans;
        for(int i=n; i>0; i--){
            if(hash[i]) ans.push_back(-i);
        }
        for(int i=1; i<=n; i++){
            if(!hash[i]) ans.push_back(i);
        }

        return ans;
    }
};