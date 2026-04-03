#define ll long long

class Solution {
public:
    long long maxPoints(vector<int>& t1, vector<int>& t2, int k) {
        int n = t1.size();

        vector<pair<int, int>> diff(n);
        for(int i=0; i<n; i++){
            diff[i] = {t1[i]-t2[i], i};
        }

        sort(diff.rbegin(), diff.rend());
        ll ans = 0;
        for(int i=0; i<n; i++){
            int ind = diff[i].second;
            if(i < k){
                ans += t1[ind];
            }
            else ans += max(t1[ind], t2[ind]);
        }

        return ans;
    }
};