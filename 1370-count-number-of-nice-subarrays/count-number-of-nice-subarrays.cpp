class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int o = 0;
        vector<int> pref(n, 0);
        for(int i=0; i<n; i++){
            if(nums[i]&1) o++;
            pref[i] = o;
        }

        unordered_map<int, int> hash;
        hash.insert({0, 1});

        int cnt = 0;

        for(int i=0; i<n; i++){
            if(hash.find(pref[i]-k) != hash.end()){
                cnt += hash[pref[i]-k];
            }
            hash[pref[i]]++;
        }

        return cnt;
    }
};