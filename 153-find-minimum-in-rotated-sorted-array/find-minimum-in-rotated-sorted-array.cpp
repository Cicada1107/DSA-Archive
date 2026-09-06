class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n-1;

        if(n == 1) return nums[0];
        if(nums[0] < nums[n-1]) return nums[0];

        while(l < r){
            int mid = l + (r-l)/2;
            if(nums[mid] < nums[0]){
                r = mid;
            }else{
                l = mid+1;
            }
        }

        return nums[l];
    }
};