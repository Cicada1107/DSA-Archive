#define ll long long

class Solution {
private:
    vector<ll> pref;
    ll n;
    string s;
    int flat, enc;
    ll dfs(int i, int j){
        ll len = j-i+1;
        ll ones = pref[j]-(i==0?0:pref[i-1]);

        ll cost;
        if(ones == 0) cost = flat;
        else{
            cost = 1LL*len*ones*enc;
        }

        if(!(len&1)){
            int mid = (i+j)/2;
            cost = min(cost, dfs(i, mid) + dfs(mid+1, j));
        }

        return cost;
    }

public:
    long long minCost(string s, int encCost, int flatCost) {
        this->s = s;
        this->n = s.length();
        this->pref.assign(n, 0);
        this->flat = flatCost;
        this->enc = encCost;

        pref[0] = (s[0] == '1'?1:0);
        for(int i=1; i<n; i++){
            pref[i] = pref[i-1] + (s[i] == '1'?1:0);
        }

        return dfs(0, n-1);
    }
};