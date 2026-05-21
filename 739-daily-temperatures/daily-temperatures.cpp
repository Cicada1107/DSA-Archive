// Next greatest index

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        int n = nums.size();
        vector<int> ngi(n);
        stack<int> s;
        for(int i=0; i<n; i++){
            while(!s.empty() && nums[i]>nums[s.top()]){
                ngi[s.top()] = i-s.top();
                s.pop();
            }
            s.push(i);
        }
        return ngi;
    }
};