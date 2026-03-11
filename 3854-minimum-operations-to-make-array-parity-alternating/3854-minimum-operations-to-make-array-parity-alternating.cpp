class Solution {
private:
    vector<int> solve(vector<int> &nums, bool even){
        int op = 0;
        int maxi = INT_MIN, mini = INT_MAX;

        for(auto num: nums){
            if((num%2 && even) || ((num%2)==0 && !even)){
                op++;
                maxi = max(num-1, maxi);
                mini = min(num+1, mini);
            }
            else{
                maxi = max(maxi, num);
                mini = min(mini, num);
            }
            even = !even;
        }
        return {op, maxi-mini};
    }

public:
    vector<int> makeParityAlternating(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return {0, 0};
        
        unordered_set<int> st(nums.begin(), nums.end());
        if(st.size() == 1) return {(int)n/2, 1};

        vector<int> a = solve(nums, 0);
        vector<int> b = solve(nums, 1);

        if(a[0] == b[0]) return a[1] < b[1] ? a : b;
        return a[0] < b[0] ? a : b;
    }
};