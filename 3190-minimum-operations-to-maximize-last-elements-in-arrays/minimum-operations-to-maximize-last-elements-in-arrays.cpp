class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int a = nums1[n-1], b = nums2[n-1];


        // case 1: don't swap the last elements
        int swap1=0;
        int flag1=0;
        for(int i=0; i<n-1; i++){
            if(nums1[i]<=a && nums2[i]<=b){
                continue;
            }
            else if(nums2[i] <= a && nums1[i] <= b){
                swap1++;
            }
            else{
                flag1 = 1;
                break;
            }
        }

        // case 2: swap the last elements
        int swap2=1;
        int flag2=0;
        for(int i=0; i<n-1; i++){
            if(nums1[i]<=b && nums2[i]<=a){
                continue;
            }
            else if(nums1[i] <= a && nums2[i] <= b){
                swap2++;
            }
            else{
                flag2=1;
                break;
            }
        }

        if(flag1 && flag2){
            return -1;
        }

        return min(swap1, swap2);
    }
};