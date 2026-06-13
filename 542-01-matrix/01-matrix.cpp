class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int n = grid.size(), m = grid[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 0) q.push({i, j});
                else grid[i][j] = INT_MAX;
            }
        }

        vector<pair<int, int>> directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        while(!q.empty()){
            auto [i, j] = q.front();
            q.pop();

            for(auto &[dx, dy]: directions){
                int ci = i + dx, cj = j + dy;
                if(ci<0 || cj<0 || ci>=n || cj>=m || grid[ci][cj] <= grid[i][j]+1) continue;
                grid[ci][cj] = grid[i][j]+1;
                q.push({ci, cj});
            }
        }

        return grid;
    }
};