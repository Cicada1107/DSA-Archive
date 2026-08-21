class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        vector<int> pref(n, 0);

        pref[0] = nums[0];
        for(int i=1; i<n; i++){
            pref[i] = pref[i-1]+nums[i];
        }

        int ans = 0;
        unordered_map<int, int> hash;
        hash[0] = 1;
        for(int i=0; i<n; i++){
            if(hash.find(pref[i]-goal) != hash.end()){
                ans += hash[pref[i]-goal];
            }
            hash[pref[i]]++;
        }
        

        return ans;
    }
};