/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func rightSideView(root *TreeNode) []int {
    ans := []int{}
    if root == nil {
        return nil
    }
    q := []*TreeNode{root}
    for len(q) != 0 {
        l := len(q)
        
        for i := 0; i<l; i++ {
            node := q[0]
            q = q[1:]
            if i == l-1 {
                ans = append(ans, node.Val)
            }
            if node.Left != nil {
                q = append(q, node.Left)
            }
            if node.Right != nil {
                q = append(q, node.Right)
            }
        }
        
    }

    return  ans
}