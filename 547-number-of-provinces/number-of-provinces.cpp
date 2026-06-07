class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int cnt = 0;
        vector<bool> vis(n, false);
        for(int i=0; i<n; i++){
            if(vis[i]) continue;
            cnt++;
            queue<int> q;
            q.push(i);
            while(!q.empty()){
                int node = q.front();
                q.pop();
                vis[node] = true;
                for(int j=0; j<n; j++){
                    if(vis[j] || i == j || isConnected[node][j] != 1) continue;
                    q.push(j);
                }
            }
        }

        return cnt;
    }
};