class Solution {
private:
    set<string> words;
    string s;
    int n;
    vector<vector<int>> dp;

    bool f(int i, int j){
        string str = s.substr(i, j-i+1);

        if(dp[i][j] != -1) return dp[i][j];
        if(words.find(str) != words.end()) return dp[i][j] = true;

        for(int x=i; x<j; x++){
            if(f(i, x) && f(x+1, j)) return dp[i][j] = true;
        }

        return dp[i][j] = false;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        this->words.insert(wordDict.begin(), wordDict.end());
        this->s = s;
        this->n = s.length();

        dp.assign(n, vector<int> (n, -1));

        return f(0, n-1);
    }
};