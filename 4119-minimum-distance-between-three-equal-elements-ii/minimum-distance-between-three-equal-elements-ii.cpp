class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> hash;
        int n = nums.size();
        for(int i=0; i<n; i++){
            hash[nums[i]].push_back(i);
        }

        int ans = INT_MAX;
        for(auto &it: hash){
            auto indices = it.second;
            int len = indices.size();
            if(len<3) continue;
            int l = 0, r = 2;
            while(r<len){
                int a = indices[l], b=indices[l+1], c = indices[r];
                ans = min(ans, abs(a-b) + abs(b-c) + abs(c-a));
                l++; r++;
            }
        }

        return (ans == INT_MAX ? -1 : ans);
    }
};