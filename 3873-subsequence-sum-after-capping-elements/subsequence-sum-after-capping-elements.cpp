#define ll long long

class Solution {
public:
    vector<bool> subsequenceSumAfterCapping(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<bool>> dp(n+1, vector<bool> (k+1, 0));
        dp[0][0] = true;
        for(int i=1; i<=n; i++){
            for(int s=0; s<=k; s++){
                bool pick = 0, notPick = dp[i-1][s];
                if(s>=nums[i-1]) pick = dp[i-1][s-nums[i-1]];
                dp[i][s] = pick | notPick;
            }
        }

        vector<bool> ans(n, false);
        for(int x=1; x<=n; x++){
            auto z_ = upper_bound(nums.begin(), nums.end(), x);
            if(z_ == nums.end()) ans[x-1] = dp[n][k];
            else{
                int z = z_ - nums.begin();
                for(int sum=0; sum<=k; sum++){
                    if(dp[z][sum] && ((k-sum)%x)==0 && k-sum <= (n-z)*x){
                        ans[x-1] = true;
                        break;
                    }
                }
            }
        }

        return ans;
    }
};