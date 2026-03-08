class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> psi(n, -1), nsi(n, n);
        stack<int> st;
        for(int i=0; i<n; i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                nsi[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && heights[st.top()] > heights[i]){
                psi[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        int ans = 0;
        for(int i=0; i<n; i++){
            ans = max((nsi[i] - psi[i] -1) * heights[i], ans);
        }
        return ans;
    }
};