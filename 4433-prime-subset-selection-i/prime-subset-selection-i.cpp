class Solution {
private:
    vector<bool> isPrime;

    void sieve(int &n){
        isPrime.assign(n+1, 1);

        isPrime[0] = isPrime[1] = 0;
        for(int p=2; p*p<=n; p++){
            if(isPrime[p]){
                for(int i=p*p; i<=n; i+=p){
                    isPrime[i] = false;
                }
            }
        }
    }


public:
    vector<int> maxPrimes(int n, int s) {
        sieve(n);

        cout<<isPrime.size();

        int sum=s;
        vector<int> ans;

        for(int i=2; i<=n; i++){
            if(isPrime[i] && sum-i >= 0){
                ans.push_back(i);
                sum-=i;
            }
        }

        return ans;
    }
};