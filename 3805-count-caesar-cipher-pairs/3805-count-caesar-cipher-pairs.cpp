#define ll long long

class Solution {
public:
    long long countPairs(vector<string>& words) {
        unordered_map<string, int> hash;
        for(auto word: words) hash[word]++;
        ll cnt = 0;
        for(auto s: words){
            hash[s]--;
            for(int x=0; x<26; x++){
                string t = s;
                for(int i=0; i<t.length(); i++){
                    t[i] = char((s[i] - 'a' + x) % 26 + 'a');
                }
                if(hash.find(t) != hash.end()) cnt += hash[t];
            }
        }
        return cnt;
    }
};