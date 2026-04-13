class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];

        vector<int> nums1(nums.begin(), nums.begin()+n-1);
        vector<int> nums2(nums.begin()+1, nums.begin()+n);
        

        vector<int> dp(n, 0);

        // case 1: include the first house, so exclude the last house
        for(int i=1; i<n; i++){
            int pick=0, notPick=0;
            if(i>=2) pick = dp[i-2]+nums1[i-1];
            else pick = nums1[i-1];
            notPick = dp[i-1];
            dp[i] = max(pick, notPick);
        }
        int case1 = dp[n-1];
        // cout<<case1<<endl;

        dp.clear();
        // case 2: include the last house, so exclude the first house
        for(int i=1; i<n; i++){
            int pick=0, notPick=0;
            if(i>=2) pick = dp[i-2]+nums2[i-1];
            else pick = nums2[i-1];
            notPick = dp[i-1];
            dp[i] = max(pick, notPick);
        }

        int case2 = dp[n-1];
        return max(case1, case2);
    }
};