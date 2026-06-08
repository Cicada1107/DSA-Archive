func canFinish(n int, prerequisites [][]int) bool {
    // topo sort
    graph := make([][]int, n)
    inDegree := make([]int, n)
    for _, i := range prerequisites {
        graph[i[1]] = append(graph[i[1]], i[0])
        inDegree[i[0]]++
    }

    var q []int
    for i:=0; i<n; i++ {
        if inDegree[i] == 0 {
            q = append(q, i)
        }
    }

    var ans []int
    for len(q) != 0 {
        node := q[len(q)-1]
        q = q[:len(q)-1]
        ans = append(ans, node)
        for _, child := range graph[node] {
            inDegree[child]--;
            if inDegree[child] == 0 {
                q = append(q, child)
            }
        }
    }

    if len(ans) == n{
        return true
    }
    return false
}