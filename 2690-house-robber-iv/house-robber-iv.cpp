class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int r = *max_element(nums.begin(), nums.end());
        int l = *min_element(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;
        while(l<=r){
            int mid = l + (r-l)/2;
            int cnt = 0;
            for(int i=0; i<n; i++){
                if(nums[i] <= mid){
                    cnt++;
                    i++;
                }
            }
            if(cnt >= k){
                ans = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }

        return ans;
    }
};