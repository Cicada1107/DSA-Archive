#define ll long long

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        ll curr_sum = 0;
        ll ans = 0;
        unordered_map<int, int> hash;

        int i=0;
        for(int j=0; j<n; j++){
            curr_sum += nums[j];
            hash[nums[j]]++;

            while(hash[nums[j]] > 1){
                hash[nums[i]]--;
                curr_sum -= nums[i];
                i++;
            }

            ans = max(ans, curr_sum);
        }

        return ans;
    }
};