#define ll long long

class Solution {
private:
    vector<int> weights;
    int days;

    bool canShip(int k){
        int cnt = 1, n = weights.size();
        ll curr_sum = 0;

        for(int i=0; i<n; i++){
            if(curr_sum + weights[i] <= k){
                curr_sum += weights[i];
            }
            else if(k < weights[i]) return false;
            else{
                cnt++;
                curr_sum = weights[i];
            }
        }

        return cnt <= days;
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {
        this->weights = weights;
        this->days = days;
        
        // bs on answer bro
        ll ans;
        ll l = 0, r = accumulate(weights.begin(), weights.end(), 0LL);
        while(l <=  r){
            ll mid = l + (r-l)/2;

            if(canShip(mid)){
                ans = mid;
                r = mid-1;
            }else{
                l = mid+1;
            }
        }

        return ans;
    }
};