class Solution {
private:
    bool valid(vector<int> &hash){
        for(auto it: hash){
            if(it == 0) return false;
        }
        return true;
    }

public:
    int numberOfSubstrings(string s) {
        int n = s.length(), cnt = 0;
        vector<int> hash(3, 0);
        int i=0;
        for(int j=0; j<n; j++){
            hash[s[j] - 'a']++;
            while(valid(hash)){
                cnt += n-j;
                hash[s[i]-'a']--;
                i++;
            }
        }

        return cnt;
    }
};