// Variation of LPS DP (Solve that first if you don't remember it)

class Solution {
private:
    string s;
    int n;
    vector<vector<int>> dp;

    int solve(int i, int j){
        // returns the minimum numbmer of deletions required to make a substring i to j of the string 's' a palindrome.
        if(i >= j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == s[j]) return dp[i][j] = 0+solve(i+1, j-1);
        else{
            return dp[i][j] = 1 + min(solve(i+1, j), solve(i, j-1));
        }
    }

public:
    int almostPalindromic(string s) {
        this->n = s.length();
        this->s = s;
        this->dp.assign(n, vector<int> (n, -1));

        int ans = 1;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                int curr_ans = solve(i, j);
                if(j-i+1 >= 2 && curr_ans <= 1) ans = max(ans, j-i+1);
            }
        }

        return ans;
    }
};