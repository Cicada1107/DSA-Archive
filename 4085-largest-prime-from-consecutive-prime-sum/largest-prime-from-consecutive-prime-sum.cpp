#define ll long long

class Solution {
private:
    vector<bool> isPrime;

    void sieve(int x) {
        isPrime.assign(x + 1, true);
        isPrime[0] = isPrime[1] = false;
    
        for (int p = 2; p * p <= x; p++) {
            if (isPrime[p]) {
                for (int i = p * p; i <= x; i += p)
                    isPrime[i] = false;
            }
        }
    }

public:
    int largestPrime(int n) {
        if(n < 2) return 0;
        sieve(n);
        
        int curr_sum = 0;
        int ans = 0;
        for(int i=2; i<=n; i++){
            if(isPrime[i]){
                curr_sum += i;
                if(curr_sum > n) break;
                if(isPrime[curr_sum]) ans = curr_sum;
            }
        }

        return ans;
    }
};