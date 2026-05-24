// brute force

func longestPalindrome(s string) string {
    n := len(s)
    check := func(i, j int) bool {
        left := i
        right := j-1

        for left < right {
            if s[left] != s[right] {
                return false
            }

            left++
            right--
        }
        return true
    }

    
    curr := ""
    for i := 0; i<n; i++ {
        for j:=i; j<=n; j++ {
            if check(i, j) && j-i>len(curr) {
                curr = s[i:j]
            }
        }
    }

    return curr
}