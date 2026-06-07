class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        set<pair<int, int>> visited;
        
        pq.push({grid[0][0], 0, 0});
        while(!pq.empty()){
            auto [max_d, i, j] = pq.top();
            pq.pop();

            if(visited.count({i, j})) continue;
            visited.insert({i, j});

            if(i == m-1 && j == n-1) return max_d;
            for(auto [di, dj]: directions){
                int i_new = i+di, j_new = j+dj;
                if(i_new >= m || i_new < 0 || j_new >= n || j_new < 0) continue;
                pq.push({max(max_d, grid[i_new][j_new]), i_new, j_new});
            }
        }
        return -1;
    }
};