class Solution {
public:
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
        string s = "";
        for(auto it: chunks){
            s += it;
        }
        
        unordered_map<string, int> words;
        int n = s.length();
        string curr = "";

        for(int i=0; i<n; i++){
            if(s[i]>= 'a' && s[i]<='z'){
                curr += s[i];
            }
            else if(s[i] == '-' && i>0 && i<n-1 && islower(s[i-1]) && islower(s[i+1])){
                curr += s[i];
            }
            else{
                if(curr != "") words[curr]++;
                curr = "";
            }
        }
        if(curr != "") words[curr]++;

        vector<int> ans;
        for(auto &query: queries){
            auto it = words.find(query);
            if(it != words.end()) ans.push_back(it->second);
            else{
                ans.push_back(0);
            }
        }
        return ans;
    }
};