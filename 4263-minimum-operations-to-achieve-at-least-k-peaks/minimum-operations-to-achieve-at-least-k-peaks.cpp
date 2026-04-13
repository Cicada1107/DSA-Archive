class Solution {
private:
    long long cost(int i, const vector<int>& nums) {
        int n = nums.size();
        long long left_neighbor = nums[(i - 1 + n) % n];
        long long right_neighbor = nums[(i + 1) % n];
        
        return max(0LL, max(left_neighbor, right_neighbor) - nums[i] + 1);
    }

    long long f(int start, int end, int k, const vector<int>& nums) {
        int len = end - start + 1;
        
        if (len < k * 2 - 1) return 1e15; 

        vector<vector<long long>> dp(len + 1, vector<long long>(k + 1, 1e15));
        
        for (int i = 0; i <= len; i++) {
            dp[i][0] = 0;
        }

        for (int i = 1; i <= len; i++) {
            int real_idx = start + i - 1; 
            
            for (int p = 1; p <= k; p++) {
                long long notPick = dp[i - 1][p];
                
                long long prev_pick_cost = (i >= 2) ? dp[i - 2][p - 1] : (p == 1 ? 0 : 1e15);
                long long pick = prev_pick_cost + cost(real_idx, nums);

                dp[i][p] = min(pick, notPick);
            }
        }
        return dp[len][k];
    }

public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        if (k == 0) return 0;
        
        if (n < k * 2) return -1; 

        long long case1 = f(0, n - 2, k, nums);
        
        long long case2 = f(1, n - 1, k, nums);

        long long ans = min(case1, case2);
        
        // If both paths returned infinity, it's impossible
        return ans >= 1e15 ? -1 : ans;
    }
};