class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<vector<int>> adj(n);
        vector<int> inDegree(n, 0), ans(n);
        for(int i=0; i<n; i++) ans[i] = i;
        for(auto &edge: richer){
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            inDegree[v]++;
        }

        // debug
        // cout<<"all good"<<endl;

        queue<int> q;
        for(int node=0; node<n; node++){
            if(inDegree[node] == 0) q.push(node);
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto &neigh: adj[node]){
                inDegree[neigh]--;
                if(inDegree[neigh] == 0) q.push(neigh);
                if(quiet[ans[node]] < quiet[ans[neigh]]) ans[neigh] = ans[node];
            }
        }

        return ans;
    }
};