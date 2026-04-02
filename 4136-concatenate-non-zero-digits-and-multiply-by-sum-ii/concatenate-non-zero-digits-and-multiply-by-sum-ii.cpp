#define ll long long
const ll MOD = 1e9+7;

class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.length();
        vector<ll> prefVal(n), prefSum(n), prefCnt(n), power10(n);
        power10[0] = 1;
        for(int i=1; i<n; i++){
            power10[i] = (power10[i-1]*10) % MOD;
        }

        prefCnt[0] = (s[0] == '0' ? 0 : 1);
        prefVal[0] = (s[0] == '0' ? 0 : s[0]-'0');
        prefSum[0] = s[0]-'0';

        for(int i=1; i<n; i++){
            int digit = s[i]-'0';
            if(digit > 0){
                prefCnt[i] = prefCnt[i-1] + 1;
                prefVal[i] = (((prefVal[i-1]*10) % MOD) + digit) % MOD;
                prefSum[i] = prefSum[i-1]+digit;
            }
            else{
                prefCnt[i] = prefCnt[i-1];
                prefVal[i] = prefVal[i-1];
                prefSum[i] = prefSum[i-1];
            }
        }

        // debug
        for(auto &it: prefVal){
            cout<<it<<" ";
        }
        cout<<endl;

        vector<int> res;
        for(auto &q: queries){
            int l = q[0], r = q[1];
            ll sum = prefSum[r] - (l == 0? 0 : prefSum[l-1]);
            ll curr_val = prefVal[r];
            ll cnt = prefCnt[r] - (l == 0? 0 : prefCnt[l-1]);
            ll x = curr_val - (l == 0? 0 : (power10[cnt]*prefVal[l-1]) % MOD) + MOD;
            res.push_back((x * sum) % MOD);

            //debug
            if(l==1 && r == 9) cout<<sum<<" "<<curr_val<<" "<<x<<endl;
        }

        return res;
    }
};