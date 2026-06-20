class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // reverse the edges and then do a topo sort. Only push to answer the queues that are pushed into the queue at some point.
        int n = graph.size();

        vector<vector<int>> rev_graph(n);
        for(int node=0; node<n; node++){
            for(auto &neigh: graph[node]){
                rev_graph[neigh].push_back(node);
            }
        }

        vector<int> inDegree(n, 0);
        queue<int> q;
        for(int node=0; node<n; node++){
            for(auto &neigh: rev_graph[node]){
                inDegree[neigh]++;
            }
        }

        for(int node=0; node<n; node++){
            if(inDegree[node] == 0) q.push(node);
        }

        vector<int> ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(auto &neigh: rev_graph[node]){
                inDegree[neigh]--;
                if(inDegree[neigh] == 0) q.push(neigh);
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};