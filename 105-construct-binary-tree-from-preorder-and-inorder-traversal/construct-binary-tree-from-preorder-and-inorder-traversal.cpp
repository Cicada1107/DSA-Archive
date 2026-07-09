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
    unordered_map<int, int> hash;
    vector<int> preorder, inorder;
    
    TreeNode* build(int p_start, int p_end, int i_start, int i_end){
        if(p_start > p_end || i_start > i_end) return nullptr;
        
        int i_root = hash[preorder[p_start]];
        int l = i_root - i_start;

        TreeNode* node = new TreeNode(preorder[p_start]);

        node->left = build(p_start+1, p_start+l, i_start, i_root-1);
        node->right = build(p_start+l+1, p_end, i_root+1, i_end);
        return node;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        this->preorder = preorder;
        this->inorder = inorder;
        for(int i=0; i<inorder.size(); i++){
            hash[inorder[i]] = i;
        }

        return build(0, preorder.size()-1, 0, inorder.size()-1);
    }
};