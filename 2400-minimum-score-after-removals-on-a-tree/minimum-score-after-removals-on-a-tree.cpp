class Solution {
private:
    vector<int> nums;
    int n;
    
    vector<vector<int>> adj;
    vector<int> in, out, sum;
    int timer = 0, ans = INT_MAX;

    int dfs(int node, int parent){
        in[node] = ++timer;
        int x = nums[node];

        for(int &neigh: adj[node]){
            if(neigh == parent) continue;
            x ^= dfs(neigh, node);
        }

        sum[node] = x;
        out[node] = timer;
        return x;
    }

    int calc(int a, int b, int c){
        return max(a, max(b, c)) - min(a, min(b, c));
    }


public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        this->nums = nums;
        this->n = nums.size();
        in.assign(n, 0);
        out.assign(n, 0);
        sum.assign(n, 0);
        adj.assign(n, {});

        for(auto &e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs(0, -1);

        for(int u=1; u<n; u++){
            for(int v=u+1; v<n; v++){
                int a, b, c;
                // case 1: u is ancestor of v
                if(in[u]<in[v] && out[u]>=out[v]){
                    a = sum[0] ^ sum[u];
                    b = sum[u] ^ sum[v];
                    c = sum[v];
                }

                // case 2: v is ancestor of u
                else if(in[v]<in[u] && out[v]>=out[u]){
                    a = sum[0] ^ sum[v];
                    b = sum[v] ^ sum[u];
                    c = sum[u];
                }

                // case 3: u & v are independent
                else{
                    a = sum[0] ^ sum[u] ^ sum[v];
                    b = sum[u];
                    c = sum[v];
                }

                ans = min(ans, calc(a, b, c));
            }
        }

        return ans;
    }
};