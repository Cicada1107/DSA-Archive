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
    int ans = 0;
    TreeNode* root;

    int dfs(TreeNode* node){
        if(!node) return 0;

        int l = dfs(node->left), r = dfs(node->right);
        
        ans = max(ans, l+r);
        // return (node == root? max(l, r) : max(l, r)+1);
        return max(l, r)+1;
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        // this->root = root;
        dfs(root);
        return ans;
    }
};