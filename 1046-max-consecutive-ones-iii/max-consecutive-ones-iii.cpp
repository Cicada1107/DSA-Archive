class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, ans = 0, z = 0;
        for(int j=0; j<n; j++){
            if(nums[j] == 0) z++;
            while(z > k){
                if(nums[i] == 0) z--;
                i++;
            }

            ans = max(ans, j-i+1);
        }

        return ans;
    }
};