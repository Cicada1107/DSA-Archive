#define ll long long

class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        vector<pair<int, int>> directions = {{-1, -2}, {-1, +2}, {1, -2}, {1, 2}, {-2, -1}, {-2, +1}, {+2, -1}, {+2, +1}};

        vector<vector<vector<double>>> dp(k+1, vector<vector<double>> (n, vector<double> (n, 0)));

        dp[0][row][column] = 1;
        
        for(int moves = 1; moves<=k; moves++){

            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){

                    for(auto [di, dj]: directions){
                        int ni = i + di, nj = j + dj;

                        if(ni<0 || ni>=n || nj<0 || nj>=n) continue;
                        dp[moves][i][j] += dp[moves-1][ni][nj] / static_cast<double>(8);
                    }

                }
            }

        }

        double sum = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                sum += dp[k][i][j];
            }
        }

        return sum;
    }
};