#define ll long long

class Solution {
public:
    long long minMoves(vector<int>& balance) {
        int n = balance.size();
        ll sum = accumulate(balance.begin(), balance.end(), 0LL);
        if(sum < 0) return -1;
        int j = -1; //negative index pointer
        for(int i=0; i<n; i++){
            if(balance[i] < 0){
                j = i;
                break;
            }
        }
        if(j == -1) return 0;
        ll ans = 0;

        for(int d=1; balance[j]<0; d++){
            ll storage = 1LL*balance[(j+d) % n] + balance[(j-(d%n)+n)%n];
            ans += min(abs((ll)balance[j]), storage) * d;
            balance[j] += storage;
        }

        return ans;
    }
};