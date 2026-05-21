class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> s;
        vector<int> ngi(n, -1);
        for(int i=0; i<2*n; i++){
            while(!s.empty() && nums[s.top()%n] < nums[i%n]){
                ngi[s.top()%n] = i%n;
                s.pop();
            }
            s.push(i);
        }

        for(int i=0; i<n; i++){
            ngi[i] = (ngi[i] == -1 ? -1 : nums[ngi[i]]);
        }
        return ngi;
    }
};