class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n, nums[0]), suff(n, nums[n-1]);
        
        for(int i=1; i<n; i++){
            pref[i] = pref[i-1]*nums[i];
        }

        for(int i=n-2; i>=0; i--){
            suff[i] = suff[i+1]*nums[i];
        }

        vector<int> ans(n, 0);
        for(int i=0; i<n; i++){
            if(i==0 && i+1<n) ans[i] = suff[i+1];
            else if(i==n-1 && i-1>=0) ans[i] = pref[i-1];
            else{
                ans[i] = pref[i-1]*suff[i+1];
            }
        }

        return ans;
    }
};