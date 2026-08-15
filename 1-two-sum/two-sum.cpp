class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        int n = nums.size();
        for(int i=0; i<n; i++){
            hash[nums[i]] = i;
        }

        for(int i=0; i<n; i++){
            if(hash.count(target-nums[i]) >= 1 && hash[target-nums[i]] != i) return {i, hash[target - nums[i]]};
        }

        return {};
    }
};