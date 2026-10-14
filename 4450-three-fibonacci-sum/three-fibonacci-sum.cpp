#define ll long long

class Solution {
public:
    bool threeFibonacciSum(int n) {
        int a=0, b=1, c = 1;
        while(a + b + c < n){
            int temp = c;
            c = b+c;
            a = b;
            b = temp;
        }

        if(a+b+c == n) return true;
        return false;
    }
};