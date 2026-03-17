class Solution {
public:
    int longestArithmetic(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n, 1), suff(n, 1);
        pref[1] = 2;
        suff[n-2] = 2;
        int d = nums[0]-nums[1];
        for(int i = 2; i <n; i++) {
            if(nums[i-1]-nums[i] == d) pref[i] = pref[i-1]+1;
            else{
                d = nums[i-1] - nums[i];
                pref[i] = 2;
            }
        }
        d = nums[n-1]-nums[n-2];
        for(int i=n-3; i>=0; i--){
            if(nums[i+1]-nums[i] == d){
                suff[i] = suff[i+1]+1;
            }
            else{
                d = nums[i+1]-nums[i];
                suff[i] = 2;
            }
        }

        //debug
        // for(auto &it: pref) cout<<it<<" ";
        // cout<<endl;
        // for(auto &it: suff) cout<<it<<" ";
        // cout<<endl;

        int ans = 0;
        for(int i=0; i<n; i++){
            //not pick
            ans = max(ans, max(pref[i], suff[i]));

            // compare not-pick, left merge, right merge, left+right merge
            if(i == 0){
                ans = max(ans, suff[i+1]+1);
            }
            else if(i == n-1){
                ans = max(ans, pref[i-1]+1);
            }                     
            else{
                ans = max(ans, max(pref[i-1]+1, suff[i+1]+1));

                // left+right merge would yield pref[i-1]+suff[i+1]+1;
                if((nums[i-1] - nums[i+1]) % 2 == 0){
                    int merge_diff = (nums[i-1]-nums[i+1])/2;
                    int leftLength = 1, rightLength = 1;
                    if(i>=2 && nums[i-2]-nums[i-1] == merge_diff) 
                        leftLength = pref[i-1];
                    if(i<n-2 && nums[i+1]-nums[i+2] == merge_diff)
                        rightLength = suff[i+1];
                    ans = max(ans, leftLength + rightLength +1);
                }
            }

            //debug
            // cout<<ans<<endl;
        }

        return ans;
    }
};