class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left_max(n, -1), right_max(n, n);

        int maxi = 0;
        for(int i=0; i<n; i++){
            maxi = max(maxi, height[i]);
            left_max[i] = maxi;
        }

        maxi = 0;
        for(int i=n-1; i>=0; i--){
            maxi = max(maxi, height[i]);
            right_max[i] = maxi;
        }

        int water = 0;
        for(int i=1; i<n-1; i++){
            int l = left_max[i-1], r = right_max[i+1];
            water += max(0, min(l, r) - height[i]);
        }

        return water;
    }
};