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
    curr := root
    for curr != nil {
        if curr.Left != nil {
            p := curr.Left
            for p.Right != nil {
                p = p.Right
            }
            p.Right = curr.Right
            curr.Right = curr.Left
            curr.Left = nil
        }
        curr = curr.Right
    }
}