/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    TreeNode *p, *q;

    TreeNode* dfs(TreeNode* node){
        if(!node) return nullptr;

        if(node == p || node == q) return node;
        TreeNode *l = dfs(node->left), *r = dfs(node->right);

        // Someday I'll be free. Until then, I yearn.

        if(l && r) return node;
        else if(l) return l;
        else if(r) return r;
        else return nullptr;

    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        this->p = p;
        this->q = q;
        return dfs(root);
    }
};