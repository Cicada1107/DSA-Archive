// I wish I was never born at all.

class Solution {
public:
    int minimumOR(vector<vector<int>>& grid) {
        int ans=0;
        int m = grid.size(), n = grid[0].size();

        int mask = 0;
        for(int b = 17; b>=0; b--){
            int curr = mask | 1<<b;
            bool found = false;
            for(int i=0; i<m; i++){
                found = false;
                for(int j=0; j<n; j++){
                    if((curr & grid[i][j]) == 0){
                        found = true;
                        break;
                    }
                }
                if(!found) break;
            }
            if(found) mask = curr;
            else ans |= (1<<b);
        }

        return ans;
    }

};