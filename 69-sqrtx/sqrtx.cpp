#define ll long long

class Solution {
public:
    int mySqrt(int x) {
        ll l = 1, r = x, ans = 0;
        while(l <= r){
            ll mid = l+(r-l)/2;
            if(mid*mid <= x){
                l = mid+1;
                ans = mid;
            }
            else r = mid-1;
        }

        return ans;
    }
};