#define ll long long

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        
        // vector<ll> pref(n, nums[0]);
        ll curr_sum = 0;
        unordered_map<ll, int> hash;
        // hash[arr[0]] = 1;
        // int cnt = (arr[0] == k ? 1 : 0);
        int cnt = 0;
        
        for(int i=0; i<n; i++){
            curr_sum += nums[i];
            if(hash.find(curr_sum - k) != hash.end()) cnt += hash[curr_sum - k];
            hash[curr_sum]++;
        }
        if(hash.find(k) != hash.end()) cnt += hash[k];

        for(auto it: hash){
            cout<<it.first<<" "<<it.second<<endl;
        }

        return cnt;
    }
};