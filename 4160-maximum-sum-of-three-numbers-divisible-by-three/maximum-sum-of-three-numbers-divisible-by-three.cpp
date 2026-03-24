#define ll long long

class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> rem0, rem1, rem2;
        for(int i=0; i<n; i++){
            if(nums[i]%3 == 0) rem0.push_back(nums[i]);
            else if(nums[i]%3 == 1) rem1.push_back(nums[i]);
            else rem2.push_back(nums[i]);
        }

        // case 1: x, y, z -> 0, 0, 0
        // case 2: x, y, z -> 1, 1, 1
        // case 3: x, y, z -> 1, 2, 0
        // case 4: x, y, z -> 2, 2, 2
        ll op1 = 0, op2 = 0, op3 = 0, op4 = 0;
        
        if(rem0.size() > 2){
            for(int i = (int)rem0.size()-1; i >= (int)rem0.size()-3; i--){
                op1 += 1LL*rem0[i];
            }
        }

        if(rem2.size() >= 3){
            for(int i = (int)rem2.size()-1; i >= (int)rem2.size()-3; i--){
                op2 += 1LL*rem2[i];
            }
        }

        if(rem1.size() >= 3){
            for(int i = (int)rem1.size()-1; i >= (int)rem1.size()-3; i--){
                op3 += 1LL*rem1[i];
            }
        }

        if(rem1.size() >= 1 && rem2.size() >= 1 && rem0.size() >= 1){
            op4 = 1LL*rem2.back() + 1LL*rem1.back() + 1LL*rem0.back();
        }

        return max(op1, max(op2, max(op3, op4)));
    }
};