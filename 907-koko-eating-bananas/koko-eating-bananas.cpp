#define ll long long

class Solution {
private:
    vector<int> piles;
    int n, h;

    bool canEat(int k){
        ll cnt = 0;
        for(int i=0; i<n; i++){
            cnt += (piles[i] % k ? piles[i]/k + 1 : piles[i]/k);
        }
        return cnt <= h;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        this->h = h;
        this->n = n;

        sort(piles.begin(), piles.end());
        this->piles = piles;

        int l = 1, r = piles[n-1];
        int ans = piles[n-1];
        while(l<=r){
            int mid = l + (r-l)/2;
            if(canEat(mid)){
                ans = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }

        return ans;
    }
};