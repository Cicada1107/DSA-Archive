class Solution {
private:
    int m, n;
    string word1, word2;
    vector<vector<int>> dp;
    
    int f(int i, int j){
        if(i == 0 && j == 0) return 0;
        if(i == 0) return j;
        if(j==0) return i;

        if(dp[i][j] != -1) return dp[i][j];

        if(word1[i-1] == word2[j-1]) return dp[i][j] = f(i-1, j-1);

        return dp[i][j] = 1+min(f(i-1, j), min(f(i-1, j-1), f(i, j-1)));
    }

public:
    int minDistance(string word1, string word2) {
        m = word1.size();
        n = word2.size();
        this->word1 = word1;
        this->word2 = word2;

        dp.assign(m+1, vector<int> (n+1, -1));

        return f(m, n);
    }
};