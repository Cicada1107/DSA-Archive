class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<bool>> vis(n, vector<bool> (m, false));
        vector<pair<int, int>> directions = {{-1, 0}, {1,0}, {0,-1}, {0, 1}};
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == 'O' && !vis[i][j]){
                    vector<pair<int, int>> island;
                    bool is_safe = false;
                    
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    vis[i][j] = true;
                    
                    while(!q.empty()){
                        auto [y, x] = q.front();
                        q.pop();
                        island.push_back({y, x});
                        if(y == 0 || x == 0 || y == n-1 || x == m-1) {
                            is_safe = true;
                        }
                        
                        for(auto &[dy, dx]: directions){
                            int cy = y+dy, cx = x+dx;
                            if(cy<0 || cx<0 || cy>=n || cx>=m || vis[cy][cx] || board[cy][cx] != 'O') continue;
                            
                            vis[cy][cx] = true;
                            q.push({cy, cx});
                        }
                    }
                    
                    if(!is_safe){
                        for(auto &[y, x]: island){
                            board[y][x] = 'X';
                        }
                    }
                }
            }
        }
    }
};