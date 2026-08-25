#define ll long long

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();

        ll s_o = accumulate(cardPoints.begin(), cardPoints.end(), 0LL);
        ll s_c = s_o;

        // if(k == n) return s_o;

        vector<ll> pref(n, 0);
        pref[0] = cardPoints[0];
        for(int i=1; i<n; i++){
            pref[i] = pref[i-1] + cardPoints[i];
        }

        for(auto it: pref) cout<<it<<" ";
        cout<<endl;

        for(int i=0, j=n-k-1; j<n; i++, j++){
            if(j<0 || i<0) continue;
            ll curr_sum = pref[j] - (i == 0 ? 0 : pref[i-1]);
            s_c = min(s_c, curr_sum);
            cout<<i<<" "<<j<<" "<<curr_sum<<endl;
        }

        return s_o - s_c;
    }
};