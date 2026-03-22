// Optimized:
// We can go by each element, and for the ith element, we find the last element which is not the submask of current element, and the first element which is not the submask of the current element.
// why? Because we need this element to be the max element of a certain array (which is basically the array given by the two edges we found above). Now why so?
// it can be seen that the total OR of a set of elements is >= the max element in the set. Now since we cant go one finding each such subarray, to be able to do this in O(n) we go by each element instead and find the subarray where that element is the max, AND ALSO, to count only those subarrays where the total OR is equal to the max element we check that no other element is present which has a '1' in a bit where the max element (this element - ith element) has a zero (i.e, not a submask), because that would mean that this element is not equal to the OR as the OR would be greater than this element.
// to be able to find the last and the first said elements for each i, we use monotonic stacks or queues (as you wish) as that would be an O(n) approach.

#define ll long long 

class Solution {
public:
    long long countGoodSubarrays(vector<int>& nums) {
        int n = nums.size();
        ll ans = 0;
        vector<int> lnsi(n, -1), nnsi(n, n); // last/next Non Submask Index
        stack<int> st;
        for(int i=0; i<n; i++){
            while(!st.empty() && (nums[st.top()] | nums[i]) > nums[st.top()]){
                nnsi[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i=n-1; i>=0; i--){
            // while(!st.empty() && ( (nums[st.top()] | nums[i] > nums[st.top()]) || (nums[i] == nums[st.top()])) ){
            while(
                !st.empty() &&
                (
                    ((nums[st.top()] | nums[i]) > nums[st.top()]) ||
                    (nums[i] == nums[st.top()])
                )
            ){
                lnsi[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        //debug
        // for(auto &it: lnsi) cout<<it<<" ";
        // cout<<endl;
        // for(auto &it: nnsi) cout<<it<<" ";
        // cout<<endl;

        for(int i=0; i<n; i++){
            ans += (nnsi[i]-i)*(i-lnsi[i]);
        }

        return ans;
    }
};