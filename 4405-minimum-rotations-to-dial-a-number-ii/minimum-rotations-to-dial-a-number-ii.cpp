class Solution {
public:
    int minRotations(int n, string s) {
        auto dist = [](int a, int b) {
            return min((a-b+10)%10, (b-a+10)%10);
        };

        int last = s.back() - '0', prev = 0, base = 0, gain=INT_MIN;
        for(char c: s){
            int cur = c - '0';
            base += dist(prev, cur);
            gain = max(gain, dist(prev, cur) - dist(prev, last));
            prev = cur;
        }

        return base - gain;
    }
};