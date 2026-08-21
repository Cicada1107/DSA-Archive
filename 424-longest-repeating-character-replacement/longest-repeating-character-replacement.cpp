class Solution {
private:
    bool isValid(int len, string &s, int &k){
        if(len == 1) return true;
        int n = s.length();
        int max_freq = 0;

        vector<int> hash(26, 0);
        int i = 0;
        for(int j=0; j<n; j++){
            hash[s[j]-'A']++;

            if(j-i+1 > len){
                hash[s[i]-'A']--;
                i++;
            }

            max_freq = max(max_freq, hash[s[j] - 'A']);
            if(len - max_freq <= k) return true;
        }

        return false;

    }

public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int l=1, r=n;

        int ans = 1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(isValid(mid, s, k)){
                ans = mid;
                l = mid+1;
            }else{
                r = mid-1;
            }
        }

        return ans;
    }
};