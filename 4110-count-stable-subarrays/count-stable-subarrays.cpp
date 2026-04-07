#define ll long long

class Solution {
public:
    vector<long long> countStableSubarrays(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        // length of longest stable subarray (not subsequence) ending at the ith element
        vector<int> lss(n, 1);
        vector<int> drops;
        for(int i=1; i<n; i++){
            if(nums[i] >= nums[i-1]) lss[i] = lss[i-1]+1;
            else{
                drops.push_back(i);
            }
        }

        vector<ll> prefSum(n);
        prefSum[0] = lss[0];
        for(int i=1; i<n; i++){
            prefSum[i] = prefSum[i-1] + lss[i];
        }

        vector<ll> ans;
        for(auto &query: queries){
            int l = query[0], r = query[1];
            auto k_ = lower_bound(drops.begin(), drops.end(), l);
            if(k_ != drops.end() && *k_ <= r){
                int k = *k_;
                ll L = k-l;
                ll left = (L*(L+1))/2;
                ll right = prefSum[r] - (k==0? 0 : prefSum[k-1]);
                ans.push_back(left+right);

                // debug
                // cout<<left<<" "<<right<<endl;
            }
            else{
                ll L = r-l+1;
                ans.push_back((L*(L+1))/2);
            }
        }

        return ans;
    }
};