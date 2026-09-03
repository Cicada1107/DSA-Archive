class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //topological sort
        vector<int> inDegree(numCourses, 0);
        vector<vector<int>> graph(numCourses);
        
        for(auto edge: prerequisites){
            int u = edge[0], v = edge[1];
            graph[v].push_back(u);

            inDegree[u]++;
        }

        queue<int> q;
        vector<int> ans;
        for(int i=0; i<numCourses; i++){
            if(inDegree[i] == 0) q.push(i);
        }

        while(!q.empty()){
            int curr = q.front();
            q.pop();

            ans.push_back(curr);

            for(auto neigh: graph[curr]){
                inDegree[neigh]--;
                if(inDegree[neigh] == 0) q.push(neigh);
            }
        }

        if(ans.size() != numCourses) return {};
        return ans;
    }
};