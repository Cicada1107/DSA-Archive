func lengthOfLIS(nums []int) int {
    if(len(nums) == 0){
        return 0
    }
    n := len(nums)
    dp := make([]int, n)

    for i := 0; i<n; i++ {
        maxi := 0
        for j:=0; j<i; j++ {
            if nums[j] >= nums[i]{
                continue
            }
            maxi = max(maxi, dp[j])
        }
        dp[i] = maxi+1
    }
    
    maxima := 1;
    for _, x := range dp{
        maxima = max(maxima, x)
    }
    return maxima
}