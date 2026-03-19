// revision attempt

class Solution {
    string s;
    int n;
    vector<vector<int>> dp;

private:
    int solve(int i, int j){
        if(i > j) return 0;
        if(i == j) return dp[i][j] = 1;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == s[j]){
            return dp[i][j] = 2+solve(i+1, j-1);
        }
        else{
            // pick whichever yields the max out of left and right
            return dp[i][j] = max(solve(i, j-1), solve(i+1, j));
        }
        return 0;
    }

public:
    int longestPalindromeSubseq(string s) {
        this->s = s;
        this->n = s.length();
        this->dp.assign(n, vector<int> (n, -1));

        return solve(0, n-1);
    }
};