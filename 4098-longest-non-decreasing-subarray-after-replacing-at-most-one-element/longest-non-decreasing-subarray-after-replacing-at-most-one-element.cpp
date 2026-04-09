class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 1;
        if(n==2) return 2;
        vector<int> prefLNS(n, 1), suffLNS(n, 1);
        for (int i = 1; i < n; i++) {
            prefLNS[i] = (nums[i] >= nums[i-1]) ? prefLNS[i-1] + 1 : 1;
        }
        for (int i = n - 2; i >= 0; i--) {
            suffLNS[i] = (nums[i] <= nums[i+1]) ? suffLNS[i+1] + 1 : 1;
        }

        int maxi = max(*max_element(prefLNS.begin(), prefLNS.end()), *max_element(suffLNS.begin(), suffLNS.end()));
        for(int i=0; i<n; i++){
            if(i>0 && i<n-1){
                if(nums[i+1]>=nums[i-1]) maxi = max(maxi, prefLNS[i-1]+suffLNS[i+1]+1);
                else maxi = max({maxi, prefLNS[i-1] + 1, suffLNS[i+1] + 1});
            }
            else if(i==0) maxi = max(maxi, 1+suffLNS[i+1]);
            else maxi = max(maxi, prefLNS[i-1]+1);
            
        }

        return maxi;
    }
};