class Solution {
private:
    bool isBinPal(int n){
        int size = 0;
        for(int b=13; b>=0; b--){
            if(n>>b & 1){
                size = b;
                break;
            }
        }

        for(int b=size; b>size/2; b--){
            int x = (n>>b)&1, y = (n>>(size-b))&1;
            if(!((x&y)|!(x|y))) return false;
        }
        return true;
    }

public:
    vector<int> minOperations(vector<int>& nums) {
        int n= nums.size();

        // 1. Preprocess and make a list of all the binary plaindromes within the range 1 to 5000
        vector<int> bp;
        for(int i=0; i<=5000; i++){
            if(isBinPal(i)) bp.push_back(i);
        }

        //debug
        // for(auto &it: bp) cout<<it<<" ";
        // cout<<endl;

        // 2. Process each nums[i], use Binary Search to find the closest Bin. Pal.
        vector<int> res(n);
        for(int i=0; i<n; i++){
            // to the right
            int right = abs(*lower_bound(bp.begin(), bp.end(), nums[i]) - nums[i]);
            
            // to the left
            int l=0, r=bp.size()-1;
            int left=0;
            while(l <= r){
                int mid = l + (r-l)/2;
                if(bp[mid] <= nums[i]){
                    left = abs(bp[mid] - nums[i]);
                    l = mid+1;
                }
                else{
                    r = mid-1;
                }
            }

            //debug
            // cout<<left<<" "<<right<<endl;

            res[i] = min(left, right);
        }

        return res;
    }
};