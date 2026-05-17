class Solution {
    vector<vector<vector<int>>> pref;

private:
    int check(int val, int r1, int c1, int r2, int c2){
        return (pref[val][r2+1][c2+1] - pref[val][r1][c2+1] 
            - pref[val][r2+1][c1] + pref[val][r1][c1]);
    }

public:
    int countLocalMaximums(vector<vector<int>>& mat) {
        int n=mat.size(), m=mat[0].size();
        pref.assign(201, vector<vector<int>> (n+1, vector<int> (m+1, 0)));
        for(int x=1; x<=200; x++){
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    pref[x][i+1][j+1] = pref[x][i][j+1] + pref[x][i+1][j] 
                        - pref[x][i][j] + (mat[i][j] > x);
                }
            }
        }

        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int x = mat[i][j];
                if(x == 0) continue;
                int cnt = check(x, max(i-x, 0), max(j-x, 0), min(n-1, i+x), min(m-1, j+x));

                vector<pair<int, int>> forbidden_cells = 
                    {{i-x, j-x}, {i-x, j+x}, {i+x, j-x}, {i+x, j+x}};
                for(auto [r, c]: forbidden_cells){
                    if(r<0 || r>n-1 || c<0 || c>m-1) continue;
                    if(mat[r][c] > x) cnt--;
                }

                if(cnt == 0) ans++;
            }
        }
        return ans;
    }
};