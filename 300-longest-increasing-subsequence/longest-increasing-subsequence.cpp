class Solution {
private:
    int n;
    vector<int> nums;
    vector<int> memo;

    int f(int i){
        if(i>=n) return 0;

        if(memo[i] != -1) return memo[i];
        int maxi = 1;
        for(int j=i+1; j<n; j++){
            if(nums[j] > nums[i]){
                maxi = max(maxi, 1+f(j));
            }
            else maxi = max(maxi, 1);
        }

        return memo[i] = maxi;
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        this->nums = nums;
        this->n = nums.size();
        this->memo.assign(n, -1);

        int ans = 1;
        for(int i=0; i<n; i++){
            ans = max(ans, f(i));
        }
        return ans;
    }
};