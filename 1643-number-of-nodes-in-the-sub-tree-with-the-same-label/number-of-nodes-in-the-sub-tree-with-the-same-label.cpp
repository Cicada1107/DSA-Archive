class Solution {
private:
    vector<vector<int>> adj;
    vector<int> ans;
    int n;
    string labels;

    vector<int> dfs(int node, int parent){
        vector<int> hash(26, 0);
        for(int &neighbour: adj[node]){
            if(neighbour == parent) continue;
            vector<int> childHash = dfs(neighbour, node);
            for(int i=0; i<26; i++){
                hash[i] += childHash[i];
            }
        }
        hash[labels[node] - 'a']++;
        ans[node] = hash[labels[node]-'a'];
        return hash;
    }


public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        adj.assign(n, {});
        ans.assign(n, 0);
        this->n = n;
        this->labels = labels;
        for(auto &edge: edges){
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> hash(26, 0);
        dfs(0, -1);
        return ans;
    }
};