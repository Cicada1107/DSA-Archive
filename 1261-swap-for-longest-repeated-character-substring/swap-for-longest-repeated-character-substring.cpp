class Solution {
public:
    int maxRepOpt1(string text) {
        int n = text.length();
        int ans = 0;
        vector<int> cnt(26, 0);
        for(int i=0; i<n; i++){
            cnt[text[i]-'a']++;
        }

        for(auto c='a'; c<='z'; c++){
            int curr = 0, curr_cnt = 0;
            int l=0;
            for(int r=0; r<n; r++){
                if(text[r] == c) curr_cnt++;

                //shrink window if it includes more than one mismatch
                while(r-l+1 > curr_cnt+1){
                    if(text[l] == c) curr_cnt--;
                    l++;
                }

                // for valid window, check if the cnt of x in the window < full cnt
                if(curr_cnt == cnt[c-'a']) ans = max(ans, curr_cnt);
                else ans = max(ans, r-l+1);
            }
        }

        return ans;
    }
};