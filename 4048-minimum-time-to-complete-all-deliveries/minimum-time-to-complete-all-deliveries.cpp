#define ll long long

class Solution {
private:
    ll d1, d2, r1, r2;

    ll gcd(ll a, ll b){
        return b == 0 ? a : gcd(b, a%b);
    }

    bool can_complete(ll T){
        ll lcm = (r1*r2)/gcd(r1, r2);
        ll t1 = T - (T/r1), t2 = T - (T/r2), t3 = T - (T/lcm);
        return(t1 >= d1 && t2 >= d2 && t3 >= d1+d2);
    }

public:
    long long minimumTime(vector<int>& d, vector<int>& re) {
        this->d1 = d[0], this->d2 = d[1], this->r1 = re[0], this->r2 = re[1];
        ll l = d1 + d2, r = 4*(d1+d2);
        ll ans = 0;
        while(l<=r){
            ll mid = l+(r-l)/2;
            if(can_complete(mid)){
                ans = mid;
                r=mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }
};