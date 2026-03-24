#define ll long long
class Solution {
public:
    long long maximumScore(vector<int>& nums, string s) {
        int n = nums.size();
        priority_queue<int> maxHeap;
        ll ans = 0;
        for(int i=0; i<n; i++){
            maxHeap.push(nums[i]);
            if(s[i] == '1'){
                ans += maxHeap.top();
                maxHeap.pop();
            }
        }

        return ans;
    }
};