class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        vector<int> digits;
        while(x){
            digits.push_back(x%10);
            x /= 10;
        }
        int n = digits.size();
        for(int i=0; i<n; i++){
            if(digits[i] != digits[n-i-1]) return false;
        }

        return true;
    }
};