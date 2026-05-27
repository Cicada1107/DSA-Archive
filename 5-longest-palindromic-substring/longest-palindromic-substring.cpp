#define ll long long

class Solution {
private:
    const ll MOD = 1e9+7;
    const ll base = 31;
    string s;
    int n;
    int ans_start=0, ans_len=0;
    vector<ll> F, B, P;

    bool isPal(int l, int r){
        // if forward hash == backward hash, string is palindromic
        ll hf = F[r] - (l == 0 ? 0 : (F[l-1]*P[r-l+1]) % MOD);
        hf = (hf+MOD) % MOD;
        ll hb = B[l] - (r == n-1 ? 0 : (B[r+1]*P[r-l+1]) % MOD);
        hb = (hb+MOD) % MOD;

        return (hf == hb);
    }

    int oddPal(int i){
        int l=0, r=min(i, n-i-1);
        int a=0;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(isPal(i-mid, i+mid)){
                a = mid;
                l = mid+1;
            }else{
                r = mid-1;
            }
        }

        return 2*a+1;
    }

    int evenPal(int i){
        if(i+1 >= n) return 0;
        int l=0, r=min(i, n-i-2);
        int a=-1;
        while(l<=r){
            int mid = l+ (r-l)/2;
            if(isPal(i-mid, i+mid+1)){
                a = mid;
                l = mid+1;
            }else{
                r = mid-1;
            }
        }

        return (a==-1 ? 1 : 2*a + 2);
    }



public:
    string longestPalindrome(string s) {
        this->s = s;
        this->n = s.length();
        this->F.assign(n, 0);
        this->B.assign(n, 0);
        this->P.assign(n, 0);

        // Precompute powers
        P[0] = 1;
        for(int i=1; i<n; i++){
            P[i] = (P[i-1]*base) % MOD;
        }

        // build forward hash
        F[0] = s[0]-'a';
        for(int i=1; i<n; i++){
            F[i] = (F[i-1]*base + s[i]-'a') % MOD;
        }

        // build backward hash
        B[n-1] = s[n-1]-'a';
        for(int i=n-2; i>=0; i--){
            B[i] = (B[i+1]*base + s[i]-'a') % MOD;
        }

        for(int i=0; i<n; i++){
            // ans_len = max(ans_len, max(oddPal(i), evenPal(i)));
            int o = oddPal(i), e = evenPal(i);
            if(o > ans_len){
                ans_len = o;
                ans_start = i - o/2;
            }
            if(e > ans_len){
                ans_len = e;
                ans_start = i - (e/2 - 1);
            }
        }

        return s.substr(ans_start, ans_len);
    }
};