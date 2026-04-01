#define ll long long

class Solution {
public:
    int maxBalancedSubarray(vector<int>& nums) {
        int n = nums.size(), odd = 0, even = 0, ans = 0;
        map<pair<int, int>, int> hash;
        int curr_xor = 0;
        hash[{0, 0}] = -1;
        for(int i=0; i<n; i++){
            curr_xor ^= nums[i];
            if(nums[i]&1) odd++;
            else even++;
            
            pair<int, int> state = {curr_xor, odd-even};
            if(hash.count(state)){
                int j = hash[state];
                ans = max(ans, i-j);
            }else{
                hash[state] = i;
            }
        }


        return ans;
    }
};