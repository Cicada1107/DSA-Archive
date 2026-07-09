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

#define ll long long

class Solution {
private:
    unordered_map<ll, int> hash;
    int cnt = 0, target;

    void dfs(TreeNode* node, ll curr_sum){
        if(!node) return;

        curr_sum += node->val;
        if(curr_sum == target) cnt++;
        if(hash.count(curr_sum - target)) cnt += hash[curr_sum - target];

        hash[curr_sum]++;
        dfs(node->left, curr_sum);
        dfs(node->right, curr_sum);
        hash[curr_sum]--;
    }

public:
    int pathSum(TreeNode* root, int targetSum) {
        this->target = targetSum;

        dfs(root, 0);
        return cnt;
    }
};