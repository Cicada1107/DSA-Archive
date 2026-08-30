class Solution {
private:
    set<string> visited;
    unordered_map<string, vector<string>> graph;

    void dfs(vector<string> &mergedAccount, string mail){
        visited.insert(mail);
        mergedAccount.push_back(mail);

        for(auto &neighbour: graph[mail]){
            if(visited.find(neighbour) == visited.end()){
                dfs(mergedAccount, neighbour);
            }
        }
    }


public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        // make graph
        int n = accounts.size();
        for(auto account: accounts){
            string firstMail = account[1];
            for(int j = 2; j<account.size(); j++){
                string childMail = account[j];
                graph[firstMail].push_back(childMail);
                graph[childMail].push_back(firstMail);
            }
        }

        // find connected components
        vector<vector<string>> mergedAccounts;
        for(auto &account: accounts){
            string name = account[0];
            string firstMail = account[1];
            vector<string> mergedAccount;
            mergedAccount.push_back(name);

            if(visited.find(firstMail) == visited.end()){
                dfs(mergedAccount, firstMail);
                sort(mergedAccount.begin()+1, mergedAccount.end());
                mergedAccounts.push_back(mergedAccount);
            }

        }

        return mergedAccounts;
    }
};