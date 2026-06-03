func coinChange(coins []int, amount int) int {
    // dp[a] = Min no. of coins required to pick, to be able to form an amount 'a'
    dp := make([]int, amount+1)
    for i := range dp {
        dp[i] = amount+1
    }
    dp[0] = 0
    for a:=0; a<=amount; a++ {
        for _, c := range coins {
            if a >= c {
                dp[a] = min(dp[a], dp[a-c]+1)
            }
        }
    }

    if dp[amount] > amount {
        return -1
    }
    return dp[amount]
}