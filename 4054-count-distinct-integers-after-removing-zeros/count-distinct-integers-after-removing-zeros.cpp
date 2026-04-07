#define ll long long

class Solution {
private:
    long long power(long long base, long long exp) {
        long long res = 1;
        while (exp > 0) {
            if (exp&1) { 
                res *= base;
            }
            base *= base;
            exp >>= 1;
        }
        return res;
    }


public:
    long long countDistinct(long long n) {
        string s = to_string(n);
        int d = s.length();
        ll ans = 0;


        // 1. Smaller length numbers 
        // (You can also replace this with the GP Sum Formula instead to save time)
        ll base = 1;
        for(int i=0; i<d-1; i++){
            ans += base*9;
            base *= 9;
        }

        // 2. Same length numbers
        bool z = false;
        for(int i=0; i<d; i++){
            if(s[i] == '0'){
                z = true;
                break;
            }
            ans += ((s[i]-'0')-1) * power(9, d-i-1);
        }


        return (z ? ans : ans+1);
    }
};