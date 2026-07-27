#define ll long long

class Solution {
private:
    ll p = 31, m = 1e9+7;
    vector<ll> h, pow;
    int n;
    vector<int> nums;

    bool isPrefix(int start1, int end1, int start2, int end2){
        int len1 = end1 - start1 + 1;
        int len2 = end2 - start2 + 1;
        if(len2 < len1) return false;

        ll lower1 = (start1 == 0 ? 0 : h[start1-1]);
        ll lower2 = (start2 == 0 ? 0 : h[start2-1]);

        int hash1 = (h[end1] - (lower1 * pow[len1]) % m + m) % m;
        int hash2 = (h[start2+len1-1] - (lower2 * pow[len1]) % m + m) % m;

        return (hash1 == hash2);
    }

public:
    int beautifulSplits(vector<int>& nums) {
        this->n = nums.size();
        this->h.assign(n, 0);
        this->pow.assign(n, 0);
        this->nums = nums;

        pow[0] = 1;
        h[0] = nums[0];

        for(int i=1; i<n; i++){
            pow[i] = (pow[i-1]*p) % m;
            h[i] = (h[i-1]*p + nums[i]) % m;
        }

        int cnt = 0;

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n-1; j++){
                if(isPrefix(0, i, i+1, j) || isPrefix(i+1, j, j+1, n-1)){
                    cnt++;
                }
            }
        }

        return cnt;
    }
};