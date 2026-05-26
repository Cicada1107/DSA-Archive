/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func isValidBST(root *TreeNode) bool {
    var dfs func (node *TreeNode, mini, maxi int64) bool

    dfs = func (node *TreeNode, mini, maxi int64) bool {
        if node == nil {
            return true
        }

        if int64(node.Val) <= mini || int64(node.Val) >= maxi {
            return false
        }

        l := dfs(node.Left, mini, int64(node.Val))
        r := dfs(node.Right, int64(node.Val), maxi)

        if l && r {
            return true
        }
        return false
    }

    return dfs(root, math.MinInt64, math.MaxInt64)
}