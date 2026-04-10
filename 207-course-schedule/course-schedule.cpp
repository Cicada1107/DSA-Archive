class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p) {
        vector<vector<int>> adj(n);
        vector<int> inDegree(n);
        for(auto &edge: p){
            int u = edge[1], v = edge[0];
            adj[u].push_back(v);
            inDegree[v]++;
        }

        vector<int> courses;
        queue<int> q;
        for(int node=0; node<n; node++){
            if(inDegree[node] == 0) q.push(node);
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            courses.push_back(node);
            for(auto &neigh: adj[node]){
                inDegree[neigh]--;
                if(inDegree[neigh] == 0) q.push(neigh);
            }
        }

        if(courses.size() == n) return true;
        return false;
    }
};