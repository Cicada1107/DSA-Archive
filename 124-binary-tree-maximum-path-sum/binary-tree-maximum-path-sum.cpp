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
    int ans = INT_MIN;

    int dfs(TreeNode* node){
        if(!node) return 0;

        int left_sum = max(0, dfs(node->left));
        int right_sum = max(0, dfs(node->right));
        ans = max(ans, left_sum + node->val + right_sum);

        return node->val + max(left_sum, right_sum);
    }

public:
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }
};