class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int n = s.length();

        unordered_map<int, int> hash;
        int i = 0;
        for(int j=0; j<n; j++){
            hash[s[j]]++;
            while(hash[s[j]] > 1){
                hash[s[i]]--;
                if(hash[s[i]] == 0) hash.erase(s[i]);
                i++;
            }

            ans = max(ans, j-i+1);
        }

        return ans;
    }
};