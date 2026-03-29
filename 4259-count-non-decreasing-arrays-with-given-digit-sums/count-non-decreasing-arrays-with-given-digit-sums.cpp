#define ll long long
const ll MOD = 1e9+7;

class Solution {
private:
    bool check(int s, int di){
        int sum = 0;
        while(s){
            sum += s % 10;
            s /= 10;
        }

        return sum == di;
    }

public:
    int countArrays(vector<int>& d) {
        int n = d.size();
        vector<vector<ll>> dp(n, vector<ll>(5001, 0));
        for(int x=0; x<=5000; x++){
            if(check(x, d[0])) dp[0][x] = 1;
        }

        for(int i=1; i<n; i++){
            // prefix sum of previous row
            vector<ll> pref(5001);
            pref[0] = dp[i-1][0];
            for(int x=1; x<=5000; x++){
                pref[x] = (pref[x-1] + dp[i-1][x]) % MOD;
            }

            for(int x=0; x<=5000; x++){
                if(check(x, d[i])) dp[i][x] = pref[x];
            }
        }

        ll res = 0;
        for(auto &it: dp[n-1]){
            res = (res + it) % MOD;
        }

        return res;
    }
};