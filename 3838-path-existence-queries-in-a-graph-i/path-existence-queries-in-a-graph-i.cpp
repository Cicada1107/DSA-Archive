class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> hash(n);
        for(int i=0; i<n; i++) hash[i] = i;
        int l=0;
        for(int r=0; r<n; r++){
            while(abs(nums[r] - nums[l]) > maxDiff){
                l++;
            }
            hash[r] = hash[l];
        }

        // for(auto &it: hash) cout<<it<<" ";
        // cout<<endl;

        vector<bool> ans;
        for(auto &q: queries){
            int u = q[0], v = q[1];
            if(hash[v] == hash[u]) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};