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
    void dfs(TreeNode* root){
        if(!root) return;

        // cout<<"reached here: "<<root->val<<endl;

        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        dfs(root->right);
        dfs(root->left);

        return;
    }

public:
    TreeNode* invertTree(TreeNode* root) {
        dfs(root);

        return root;
    }
};