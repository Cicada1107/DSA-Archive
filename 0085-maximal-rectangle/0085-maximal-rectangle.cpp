class Solution {
private:
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

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> pref(n, vector<int> (m, 0));
        for(int i=0; i<m; i++){
            pref[0][i] = matrix[0][i] - '0';
            for(int j=1; j<n; j++){
                pref[j][i] = (matrix[j][i] == '0' ? 0 : (matrix[j][i] - '0') + pref[j-1][i]);
            }
        }


        int ans = 0;
        for(int i=0; i<n; i++){
            ans = max(ans, largestRectangleArea(pref[i]));
        }

        return ans;
    }
};