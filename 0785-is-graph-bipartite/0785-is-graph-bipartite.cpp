class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        stack<int> st;
        for(int i=0; i<n; i++){
            if(color[i] != -1) continue;
            color[i] = 0;
            st.push(i);
            while(!st.empty()){
                int curr = st.top();
                st.pop();
                for(auto &neigh: graph[curr]){
                    if(color[neigh] == color[curr]){
                        return false;
                    }
                    else{
                        if(color[neigh] != -1) continue;
                        color[neigh] = !color[curr];
                        st.push(neigh);
                    }
                }
            }
        }

        return true;
    }
};