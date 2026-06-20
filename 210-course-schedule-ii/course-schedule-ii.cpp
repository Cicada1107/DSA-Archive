class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        // directed graph b to a
        vector<vector<int>> graph(n);
        for(auto &edge: prerequisites){
            int u = edge[0], v = edge[1];
            graph[v].push_back(u);
        }

        vector<int> indegree(n, 0);
        for(int node=0; node<n; node++){
            for(auto &neigh: graph[node]){
                indegree[neigh]++;
            }
        }

        queue<int> q;
        for(int node=0; node<n; node++){
            if(indegree[node]==0) q.push(node);
        }

        vector<int> ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(auto &neigh: graph[node]){
                indegree[neigh]--;
                if(indegree[neigh] == 0) q.push(neigh);
            }
        }

        if(ans.size() != n) return {};
        return ans;
    }
};