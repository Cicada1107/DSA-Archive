#define ll long long

class Solution {
public:
    long long lastInteger(long long n) {
        ll a = 1, step = 0, len = n, d=1;
        while(len>1){
            len = (n-a)/d + 1;
            if(!(len&1) && step&1) a += d;
            d *= 2;
            step++;
            
            // debug
            // cout<<a<<endl;
        }

        return a;
    }
};