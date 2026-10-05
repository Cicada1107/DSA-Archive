class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        int m = grid.size(), n = grid[0].size();
        vector<pair<int, int>> directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == '1'){
                    cnt++;
                    queue<pair<int, int>> q;
                    q.push({i,j});
                    grid[i][j] = '2';

                    while(!q.empty()){
                        auto [x, y] = q.front();
                        q.pop();

                        for(auto [dx, dy]: directions){
                            int nx = x+dx, ny = y+dy;

                            if(nx>=0 && ny>=0 && nx<m && ny<n && grid[nx][ny] == '1'){
                                grid[nx][ny] = '2';
                                q.push({nx, ny});
                            }
                        }
                    }
                }
            }
        }

        return cnt;
    }
};