class Solution {
public:
    int minRotations(string s) {
        int n = 10;
        int ans = 0;
        int i = 0;
        for(int x=0; x<n; x++){
            int j = s[x] - '0';
            ans += min((j-i+n)%10, (i-j+n)%10);
            i = j;
        }

        return ans;
    }
};