func longestPalindrome(s string) string {
    n := len(s)

    expand := func (l, r int) string {
        for l>=0 && r<n && s[l] == s[r] {
            l--
            r++
        }
        return s[l+1: r]
    }

    ans := ""

    for i:=0; i<n; i++ {
        odd := expand(i, i)
        if len(odd) > len(ans){
            ans = odd
        }

        even := expand(i, i+1)
        if len(even) > len(ans){
            ans = even
        }
    }

    return ans
}