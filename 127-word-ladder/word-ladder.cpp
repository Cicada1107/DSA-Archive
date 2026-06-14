class Solution {
private:
    int diff(int i, int j, vector<string> &wordList){
        if(i == j) return 0;
        int cnt = 0;
        for(int x=0; x<wordList[i].size(); x++){
            if(wordList[i][x] != wordList[j][x]) cnt++;
        }
        return cnt;
    }

public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        bool found = false;
        for(auto &word: wordList) if(word == endWord) found = true;
        if(!found) return 0;

        wordList.push_back(beginWord);
        int n = wordList.size();

        // create a graph, each word represents a node, edge between two nodes only if a single char difference, find shortest path in this undirected graph uisng BFS.

        unordered_map<string, vector<string>> graph;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(diff(i, j, wordList) == 1){
                    string u = wordList[i], v = wordList[j];
                    graph[u].push_back(v);
                    graph[v].push_back(u);
                }
            }
        }

        queue<pair<string, int>> q;
        unordered_map<string, bool> vis;
        q.push({beginWord, 0});
        vis[beginWord] = true;
        while(!q.empty()){
            auto [node, d] = q.front();
            q.pop();
            if(node == endWord) return d+1;
            for(string &neigh: graph[node]){
                if(vis.count(neigh)) continue;
                vis[neigh] = true;
                q.push({neigh, d+1});
            }
        }

        return 0;
    }
};