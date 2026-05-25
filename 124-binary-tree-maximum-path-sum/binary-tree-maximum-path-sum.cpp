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
    int ans = -1e9;

    int dfs(TreeNode* node){
        if(!node) return 0;

        int l = max(0, dfs(node->left));
        int r = max(0, dfs(node->right));

        ans = max(ans, node->val+l+r);
        return max(l, r) + node->val;
    }

public:
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }
};