#define ll long long

class Solution {
private:
    bool canShip(vector<int> &weights, int &days, ll cap){
        ll cnt = 1, curr = 0;
        for(int i=0; i<weights.size(); i++){
            if(weights[i] > cap) return false;
            if(curr + weights[i] <= cap){
                curr += weights[i];
            }else{
                cnt++;
                curr = weights[i];
            }
        }

        return (cnt <= (ll)days);
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {
        ll l = 0, r = accumulate(weights.begin(), weights.end(), 0LL);

        int n  = weights.size();
        ll ans = 0;
        while(l <= r){
            ll mid = l + (r-l)/2;
            if(canShip(weights, days, mid)){
                ans = mid;
                r = mid-1;
            }else{
                l = mid+1;
            }

            cout<<mid<<" "<<canShip(weights, days, mid)<<endl;
        }

        return ans;
    }
};