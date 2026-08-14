class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n = s.length();
        int len = 0;
        unordered_map<char, int> hash;

        int i = 0;
        for(int j=0; j<n; j++){
            hash[s[j]]++;

            while(hash[s[j]] > 1){
                hash[s[i]]--;
                i++;
            }
            len = max(len, j-i+1);
        }

        return len;
    }
};