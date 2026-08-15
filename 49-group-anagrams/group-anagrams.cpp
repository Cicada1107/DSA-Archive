class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> hash;
        for(int i=0; i<n; i++){
            string curr = strs[i];
            sort(curr.begin(), curr.end());
            hash[curr].push_back(strs[i]);
            // if(hash.find(strs[i]) != hash.end()) hash[curr].push_back(strs[i]);
            // else{
            //     hash[curr].push_back(strs[i]);
            // }
        }

        for(auto it: hash){
            ans.push_back(it.second);
        }

        return ans;
    }
};