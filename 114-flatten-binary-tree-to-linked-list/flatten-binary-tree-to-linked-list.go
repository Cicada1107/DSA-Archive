/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func flatten(root *TreeNode)  {
    if root == nil {
        return
    }

    var nodes []*TreeNode

    var dfs func(node *TreeNode)

    dfs = func (node *TreeNode) {
        if node == nil {
            return
        }

        nodes = append(nodes, node)
        dfs(node.Left)
        dfs(node.Right)
    }

    dfs(root)

    for i:=0; i<len(nodes)-1; i++ {
        nodes[i].Right = nodes[i+1]
        nodes[i].Left = nil
    }

}