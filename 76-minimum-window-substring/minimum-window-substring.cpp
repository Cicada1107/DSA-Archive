class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.length(), n = t.length();
        if(s.empty() || t.empty() || s.length() < t.length()) return "";

        vector<int> hash(128, 0);

        for(char c: t){
            hash[c]++;
        }

        int left=0, right=0;
        int requiredChars = n;
        int minLen = INT_MAX;
        int startChar = 0;

        while(right < m){
            if(hash[s[right]] > 0){
                requiredChars--;
            }

            hash[s[right]]--;
            right++;
            
            while(requiredChars == 0){
                if(minLen > right-left){
                    minLen = right-left;
                    startChar = left;
                }

                hash[s[left]]++;
                if(hash[s[left]] > 0){
                    requiredChars++;
                }
                left++;
            }
        }

        if(minLen == INT_MAX) return "";
        return s.substr(startChar, minLen);
    }
};