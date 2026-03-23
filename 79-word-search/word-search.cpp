class Solution {

private:
    int m, n, l;
    string word;
    vector<vector<char>> board;

    bool backtrack(int i, int j, int curr){
        // curr == current index of the word
        if(curr >= l) return true;
        if(i<0 || i>=m || j<0 || j>=n) return false;

        if(word[curr] == board[i][j]){
            board[i][j] = '#';
            if(backtrack(i-1, j, curr+1) || backtrack(i, j+1, curr+1) || backtrack(i+1, j, curr+1) || backtrack(i,j-1, curr+1)) return true;

            board[i][j] = word[curr];
            return false;
        }

        return false;
    }
    

public:
    bool exist(vector<vector<char>>& board, string word) {
        this->m = board.size();
        this->n = board[0].size();
        this->l = word.size();
        this->word = word;
        this->board = board;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (backtrack(i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};