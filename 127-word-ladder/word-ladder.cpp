class Solution {
private:
    int dist(string &u, string &v){
        int cnt = 0;
        for(int i=0; i<u.length(); i++){
            if(u[i] != v[i]) cnt++;
        }

        return cnt;
    }

public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordList.push_back(beginWord);
        int n = wordList.size();
        unordered_map<string, vector<string>> graph(n);

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                string u = wordList[i], v = wordList[j];
                if(dist(u, v) == 1){
                    graph[u].push_back(v);
                    graph[v].push_back(u);
                }
            }
        }

        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        set<string> visited;

        while(!q.empty()){
            auto [node, depth] = q.front();
            q.pop();

            if(node == endWord) return depth;

            for(auto &neighbour: graph[node]){
                if(visited.find(neighbour) == visited.end()){
                    visited.insert(neighbour);
                    q.push({neighbour, depth+1});
                }
            }
        }

        return 0;
    }
};