class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        queue<tuple<int, int, int>> q; // {y, x, depth}
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    q.push({i, j, 0});
                }
            }
        }


        int cnt = 0;

        vector<pair<int, int>> directions = {{-1, 0}, {0, -1}, {0, +1}, {+1, 0}};
        while(!q.empty()){
            auto [i, j, d] = q.front();
            q.pop();
            cnt = max(cnt, d);
            for(auto [di, dj]: directions){
                int ni = i+di, nj = j+dj;
                if(ni<0 || ni>=n || nj<0 || nj>=m || grid[ni][nj] != 1) continue;
                if(grid[ni][nj] == INT_MIN) continue;
                grid[ni][nj] = INT_MIN;
                q.push({ni, nj, d+1});
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1) return -1;
            }
        }

        return cnt;
    }
};