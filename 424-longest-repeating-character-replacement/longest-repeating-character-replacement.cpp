class Solution {
private:
    bool isValid(const string& s, int k, int len) {
        int n = s.length();
        if (len == 0) return true;

        vector<int> freq(26, 0);
        int max_freq = 0;

        // Populate the first window of size `len`
        for (int i = 0; i < len; i++) {
            freq[s[i] - 'A']++;
            max_freq = max(max_freq, freq[s[i] - 'A']);
        }

        if (len - max_freq <= k) return true;

        // Slide the window of size `len` across the string
        for (int i = len; i < n; i++) {
            freq[s[i] - 'A']++;
            freq[s[i - len] - 'A']--;

            // Recompute max_freq for the current window
            max_freq = 0;
            for (int c = 0; c < 26; c++) {
                max_freq = max(max_freq, freq[c]);
            }

            if (len - max_freq <= k) return true;
        }

        return false;
    }

public:
    int characterReplacement(string s, int k) {
        int n = s.length();

        int l = 1, r = n;
        int ans = 0;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(isValid(s, k, mid)){
                ans = mid;
                l = mid+1;
            }else{
                r = mid-1;
            }
        }

        return ans;
    }
};