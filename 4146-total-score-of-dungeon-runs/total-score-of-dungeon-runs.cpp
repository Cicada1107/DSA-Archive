#define ll long long

class Solution {
public:
    long long totalScore(int hp, vector<int>& d, vector<int>& r) {
        ll score = 0;
        int n = d.size();

        vector<ll> p(n, 0);
        p[0] = d[0];
        for(int i=1; i<n; i++){
            p[i] = p[i-1] + d[i];
        }

        for(int i=0; i<n; i++){
            if(hp - p[i] >= r[i]) score += i+1;
            else{
                int left=0, right=i;
                int j = -1;
                while(left<=right){
                    int mid = left+(right-left)/2;
                    if(hp-(p[i]-p[mid]) >= r[i]){
                        j = mid;
                        right = mid-1;
                    }
                    else{
                        left = mid+1;
                    }
                }
                if(j > -1) score += i-j;
            }
        }

        return score;
    }
};