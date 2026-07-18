class Solution {
private:
    int m;
    int n;
    vector<pair<int, int>> directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

    bool isValidCell(int i, int j){
        if(i<m && i>=0 && j<n && j>=0) return true;
        return false;
    }

public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        this->m = grid.size();
        this->n = grid[0].size();

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> minHeap;
        
        minHeap.push({grid[0][0], 0, 0});
        grid[0][0] = -1;

        while(!minHeap.empty()){
            auto [curr_sum, i, j] = minHeap.top();
            minHeap.pop();

            if(i == m-1 && j == n-1 && health > curr_sum) return true;

            for(auto [di, dj]: directions){
                int ni = i + di, nj = j + dj;
                if(isValidCell(ni, nj) && grid[ni][nj] != -1){
                    minHeap.push({curr_sum+grid[ni][nj], ni, nj});
                    grid[ni][nj] = -1;
                }
            }
        }

        return false;
    }
};