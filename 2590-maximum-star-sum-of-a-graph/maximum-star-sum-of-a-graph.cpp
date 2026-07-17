#define ll long long

class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        queue<int> q;
        int n = vals.size();
        vector<bool> vis(n, false);
        vector<vector<int>> graph(n);
        ll ans = INT_MIN;

        for(auto &edge: edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        priority_queue<int, vector<int>, greater<int>> minHeap;

        for(int src = 0; src < n; src++){
            if(vis[src]) continue;

            q.push(src);
            vis[src] = true;

            while(!q.empty()){
                int node = q.front();
                q.pop();

                for(int neigh: graph[node]){
                    if(!vis[neigh]) q.push(neigh);
                    vis[neigh] = true;

                    if(vals[neigh] >= 0) minHeap.push(vals[neigh]);
                    if(minHeap.size() > k) minHeap.pop();
                }

                ll sum =vals[node];
                while(!minHeap.empty()){
                    sum += minHeap.top();
                    minHeap.pop();
                }
                ans = max(ans, sum);
            }
        }

        return ans;
    }
};