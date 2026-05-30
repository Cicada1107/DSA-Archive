/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int in[100005], out[100005], depth[100005];
    int timer = 0;

    void dfs(TreeNode* node, int d){
        if(!node) return;

        in[node->val] = ++timer;
        depth[timer] = d;

        dfs(node->left, d+1);
        dfs(node->right, d+1);

        out[node->val] = timer;
    }

public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        dfs(root, 0);

        // Build prefix max and suffix max on the depth array
        //timer is also equal to the number of nodes now
        vector<int> pref(timer+1, 0), suff(timer+1, 0);
        pref[1] = depth[1];
        for(int i=2; i<=timer; i++){
            pref[i] = max(pref[i-1], depth[i]);
        }
        suff[timer]=depth[timer];
        for(int i=timer-1; i>=1; i--){
            suff[i] = max(suff[i+1], depth[i]);
        }

        vector<int> ans;
        for(auto &q: queries){
            int l = (in[q] == 1 ? 0 : pref[in[q]-1]);
            int r = (out[q] == timer ? 0 : suff[out[q]+1]);
            ans.push_back(max(l, r));
        }
        return ans;
    }
};