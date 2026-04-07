#define ll long long

class Solution {
private:
    vector<vector<int>> adj;
    int n;

    void dfs(int node, vector<bool> &vis, int &cnt){
        vis[node] = true;
        cnt++;

        for(int &neigh: adj[node]){
            if(!vis[neigh]){
                dfs(neigh, vis, cnt);
            }
        }
    }

public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        this->n = (int)bombs.size();
        this->adj.assign(n, {});

        for(int i = 0; i < n; i++){
            ll x1 = bombs[i][0], y1 = bombs[i][1], r1 = bombs[i][2];
            for(int j = 0; j < n; j++){
                if(i == j) continue;
                ll x2 = bombs[j][0], y2 = bombs[j][1];
                ll dx = x1 - x2, dy = y1 - y2;
                
                // FIX 1: Only check against bomb i's radius
                if(dx*dx + dy*dy <= r1*r1){
                    adj[i].push_back(j);
                }
            }
        }

        int maxi = 0;
        for(int u=0; u<n; u++){
            vector<bool> vis(n, false);
            int cnt = 0;
            dfs(u, vis, cnt);
            maxi = max(maxi, cnt);
        }
        return maxi;
    }
};