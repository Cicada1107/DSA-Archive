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
public:
    int amountOfTime(TreeNode* root, int start) {
        if(!root) return 0;
        TreeNode* src;
        unordered_map<TreeNode*, TreeNode*> parent;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            if(node->val == start) src = node;

            if(node->left){
                parent[node->left] = node;
                q.push(node->left);
            }
            if(node->right){
                parent[node->right] = node;
                q.push(node->right);
            }
        }

        
        queue<pair<TreeNode*, int>> q2;
        unordered_map<TreeNode*, bool> visited;
        int ans = 0;
        q2.push({src, 0});
        visited[src] = true;
        while(!q2.empty()){
            auto [node, t] = q2.front();
            q2.pop();
            ans = max(t, ans);

            cout<<node->val<<" "<<t<<endl;

            if(parent.count(node) && !visited[parent[node]]){
                q2.push({parent[node], t+1});
                visited[parent[node]] = true;
            }
            if(node->left && !visited[node->left]){
                q2.push({node->left, t+1});
                visited[node->left] = true;
            }
            if(node->right && !visited[node->right]){
                q2.push({node->right, t+1});
                visited[node->right] = true;
            }
        }

        return ans;
    }
};