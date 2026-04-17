class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> hash;
        int n = nums.size();
        hash[0] = -1;
        int max_len = 0;
        int curr_sum = 0;
        for(int i=0; i<n; i++){
            curr_sum += (nums[i] == 0 ? -1 : 1);
            if(hash.count(curr_sum) > 0){
                max_len = max(max_len, i-hash[curr_sum]);
            }
            else{
                hash[curr_sum] = i;
            }
        }
        return max_len;
    }
};