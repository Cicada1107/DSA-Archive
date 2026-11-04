#define ll long long

class Solution {
private:
    int countDigits(int x){
        int d = 0;
        while(x){
            x/=10;
            d++;
        }

        return d;
    }

public:
    int minMergedInteger(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for(int i=0; i<n-1; i+=2){
            int d = countDigits(nums[i+1]);
            int curr = nums[i];
            while(d--){
                curr*=10;
            }
            ans.push_back(curr + nums[i+1]);
        }


        return *min_element(ans.begin(), ans.end());
    }
};