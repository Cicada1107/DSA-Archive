class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> graph(n);
        for(auto &it: flights){
            graph[it[0]].push_back({it[1], it[2]}); //{node, weight}
        }

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap; //{depth, distance, node}

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        vector<int> depth(n, INT_MAX);
        depth[src] = 0;
        
        minHeap.push({0, 0, src});
        while(!minHeap.empty()){
            auto curr = minHeap.top();
            minHeap.pop();

            int curr_d = curr[1], curr_depth = curr[0], curr_node = curr[2];

            for(auto [neigh, neigh_dist]: graph[curr_node]){
                if(curr_d + neigh_dist <= dist[neigh] && curr_depth + 1 <= k+1){
                    dist[neigh] = curr_d + neigh_dist;
                    depth[neigh] = curr_depth + 1;
                    minHeap.push({depth[neigh], dist[neigh], neigh});
                }
            }
        }

        if(dist[dst] == INT_MAX || depth[dst] > k+1) return -1;
        return dist[dst];
    }
};