class Solution {
private:
    int m, n;
    string s;
    vector<vector<char>> board;
    vector<pair<int, int>> directions = {{0, -1}, {0, +1}, {-1, 0}, {1, 0}};

    bool dfs(int i, int j, int ind){
        // if(i<0 || j<0 || i>=m || j>=n) return false;
        if(ind == s.length()-1 && board[i][j] == s[ind]) return true;
        if(board[i][j] != s[ind]) return false;
        
        char temp = board[i][j];
        board[i][j] = '-';

        for(auto [di, dj]: directions){
            if(i+di<0 || j+dj<0 || i+di>=m || j+dj>=n) continue;
            if(board[i+di][j+dj] != '-' && dfs(i+di, j+dj, ind+1)) return true;
        }

        board[i][j] = temp;

        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        s = word;
        this->board = board;
        m = board.size();
        n = board[0].size();

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(dfs(i, j, 0)) return true;
            }
        }

        return false;
    }
};