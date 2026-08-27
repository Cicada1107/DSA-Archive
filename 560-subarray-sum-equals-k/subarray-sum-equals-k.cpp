#define ll long long

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> pref(n, 0);
        pref[0] = nums[0];
        for(int i=1; i<n; i++){
            pref[i] = pref[i-1]+nums[i];
        }

        int cnt = 0;
        unordered_map<int, int> hash;
        hash[0] = 1;
        for(int i=0; i<n; i++){
            if(hash.find(pref[i] - k) != hash.end()){
                cnt += hash[pref[i] - k];
            }
            hash[pref[i]]++;
        }

        return cnt;
    }
};