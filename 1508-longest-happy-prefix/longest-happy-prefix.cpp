// KMP ka ek part - LPS Array generation

class Solution {
public:
    string longestPrefix(string s) {
        int n = s.length();

        vector<int> lps(n, 0);
        int l=0, r=1;
        while(r<n){
            if(s[l] == s[r]){
                lps[r] = ++l;
                r++;
            }
            else{
                if(l == 0){
                    lps[r] = 0;
                    r++;
                }
                else{
                    l = lps[l-1];
                }
            }
        }

        return s.substr(0, lps.back());
    }
};