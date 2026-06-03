func coinChange(coins []int, amount int) int {
    n := len(coins)
    // sort.Ints(coins)

    dp := make([][]int, n+1)
    for i:=0; i<=n; i++{
        dp[i] = make([]int, amount+1)
    }

    for a:=0; a<=amount; a++ {
        dp[0][a] = amount+1
    }
    for i:=0; i<=n; i++ {
        dp[i][0] = 0
    }

    for i:=1; i<=n; i++ {
        for a:=1; a<=amount; a++ {
            dp[i][a] = dp[i-1][a]
            if a >= coins[i-1] {
                dp[i][a] = min(dp[i][a], dp[i][a-coins[i-1]]+1)
            }
        }
    }

    if dp[n][amount] > amount {
        return -1
    }else{
        return dp[n][amount]
    }
}