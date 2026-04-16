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
    unordered_map<TreeNode*, int> dp;
    int n;

    int dfs(TreeNode* node){
        if(node == nullptr) return 0;
        if(dp.count(node) != 0) return dp[node];
        
        int notPick = 0;
        if(node->left != nullptr) notPick += dfs(node->left);
        if(node->right != nullptr) notPick += dfs(node->right);
        
        int pick = node->val;
        if(node->left != nullptr){
            pick += dfs(node->left->left) + dfs(node->left->right);
        }
        if(node->right != nullptr){
            pick += dfs(node->right->left) + dfs(node->right->right);
        }

        return dp[node] = max(notPick, pick);
    }

public:
    int rob(TreeNode* root) {
        return dfs(root);
    }
};