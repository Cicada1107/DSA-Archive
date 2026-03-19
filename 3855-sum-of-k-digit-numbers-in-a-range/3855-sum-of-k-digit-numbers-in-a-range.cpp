#define ll long long
const ll MOD = 1e9+7;

class Solution {

private:
    ll binpow(ll a, ll b) {
        ll res = 1;
        while (b > 0) {
            if (b & 1) res = (res*a) % MOD;
            a = (a*a) % MOD;
            b >>= 1;
        }
        return res;
    }

public:
    int sumOfNumbers(int l, int r, int k) {
        ll n = r-l+1;
        ll s = 0;
        for(int i=l; i<=r; i++){
            s = (s+i) % MOD;
        }
        // ll ten_pow_k = 1;
        // for(int i=0; i<k; i++){
        //     ten_pow_k = (ten_pow_k*10) % MOD;
        // }
        // ll n_pow = 1;
        // for(int i=0; i<k-1; i++){
        //     n_pow = (n_pow*n) % MOD;
        // }

        // debug
        // cout<<s<<" "<<ten_pow_k<<" "<<n_pow<<endl;
        // cout<<(n_pow*s) % MOD<<endl;

        // return (((n_pow*s)%MOD) * (ten_pow_k-1)/9) % MOD;

        ll ten_pow = binpow(10, k);
        ll n_pow = binpow(n, k-1);
        ll nine_inv = binpow(9, 1e9 + 5);

        ll left = (n_pow * s) % MOD;
        ll right = (ten_pow - 1 + MOD) % MOD;
        right = (right * nine_inv) % MOD;

        return (left * right) % MOD;
    }
};