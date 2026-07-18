class Solution {
private:
    vector<pair<int, int>> directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    int n;
    

    bool isValidCell(int i, int j){
        if(i<n && i>=0 && j<n && j>= 0) return true;
        return false;
    }

public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        this->n = grid.size();
        
        queue<tuple<int, int, int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] != 1) grid[i][j] = -1;
                else{
                    grid[i][j] = 0;
                    q.push({i, j, 0});
                }
            }
        }

        while(!q.empty()){
            auto [i, j, d] = q.front();
            q.pop();

            for(auto [dx, dy]: directions){
                int ni = i + dx, nj = j + dy;
                if(isValidCell(ni, nj) && grid[ni][nj] == -1){
                    q.push({ni, nj, d+1});
                    grid[ni][nj] = d+1;
                }
            }
        }


        priority_queue<vector<int>> pq;                //{safeness factor, i, j} - maxHeap
        pq.push({grid[0][0], 0, 0});
        grid[0][0] = -1;

        while(!pq.empty()){
            int sf = pq.top()[0], i = pq.top()[1], j = pq.top()[2];
            pq.pop();

            if(i == n-1 && j == n-1) return sf;
            for(auto [di, dj]: directions){
                int ni = i + di, nj = j + dj;
                if(isValidCell(ni, nj) && grid[ni][nj] != -1){
                    pq.push({min(sf, grid[ni][nj]), ni, nj});
                    grid[ni][nj] = -1;
                }
            }
        }

        return -1;
    }
};