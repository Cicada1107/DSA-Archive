class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n+1);
        for(auto &edge: times){
            int u = edge[0], v = edge[1], w = edge[2];
            graph[u].push_back({v, w});
        }

        vector<int> distance(n+1, INT_MAX);
        distance[k] = 0;
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        minHeap.push({0, k});

        while(!minHeap.empty()){
            auto [curr_dist, node] = minHeap.top();
            minHeap.pop();
            for(auto &[neigh, neigh_dist]: graph[node]){
                if(curr_dist + neigh_dist < distance[neigh]){
                    distance[neigh] = curr_dist + neigh_dist;
                    minHeap.push({distance[neigh], neigh});
                }
            }
        }

        for(int i=1; i<=n; i++){
            if(distance[i] == INT_MAX) return -1;
        }
        return *max_element(distance.begin()+1, distance.end());
    }
};