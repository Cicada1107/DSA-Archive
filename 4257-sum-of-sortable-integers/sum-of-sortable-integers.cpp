//fuck this question man. Seriously.

class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();

        // 1. Precompute Inversion Points
        vector<int> prefDrops(n, 0);
        vector<int> nextDrop(n, n);

        int drops = 0;
        for(int i=0; i<n-1; i++){
            if(nums[i] > nums[i+1]) drops++;
            prefDrops[i] = drops;
        }
        prefDrops[n-1] = drops;
        
        int last_drop = n;
        for(int i=n-2; i>=0; i--){
            if(nums[i] > nums[i+1]){
                last_drop = i;
            }
            nextDrop[i] = last_drop;
        }


        // 2. Validate chunk
        auto is_valid_k = [&](int k)->bool{
            int prevMax = INT_MIN;
            for(int l=0; l<n; l+=k){
                int r = l+k-1;

                int dropCnt = 0;
                if(r > l) dropCnt = prefDrops[r-1] - (l == 0 ? 0 : prefDrops[l-1]);

                if(dropCnt > 1) return false;
                int chunkMin, chunkMax;
                if(dropCnt == 0){
                    chunkMin = nums[l];
                    chunkMax = nums[r];
                }
                else{
                    if(nums[r] > nums[l]) return false;

                    int d = nextDrop[l];
                    chunkMin = nums[d+1];
                    chunkMax = nums[d];
                }

                if(prevMax > chunkMin) return false;
                prevMax = chunkMax;
            }
            return true;
        };

            
        // 3. Process divisors and check if they are valid. If they are, add them
        int ans = 0;
        for(int k=1; k*k<=n; k++){
            if(n % k == 0){
                if(is_valid_k(k)) ans += k;

                if(k*k != n && is_valid_k(n/k)) ans += n/k;
            }
        }

        return ans;
    }
};