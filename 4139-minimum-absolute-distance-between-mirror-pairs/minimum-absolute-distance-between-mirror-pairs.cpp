class Solution {
private:
    int reversed(int x){
        int res = 0;
        while(x){
            res = res*10 + x%10;
            x /= 10;
        }
        return res;
    }
    
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> hash;
        int ans = INT_MAX;

        for(int i=0; i<n; i++){
            if(hash.count(nums[i])){
                ans = min(ans, i-hash[nums[i]]);
            }
            hash[reversed(nums[i])] = i;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};