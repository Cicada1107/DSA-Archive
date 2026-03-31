class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefMin(n, 0);
        vector<int> suffMax(n, 0);

        prefMin[0] = nums[0];
        for(int i=1; i<n; i++){
            prefMin[i] = min(prefMin[i-1], nums[i]);
        }

        suffMax[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--){
            suffMax[i] = max(suffMax[i+1], nums[i]);
        }

        for(int i=1; i<n-1; i++){
            if(prefMin[i-1] < nums[i] && suffMax[i+1] > nums[i]) return true;
        }

        return false;
    }
};