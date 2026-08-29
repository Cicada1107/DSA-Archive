class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // Next greater element
        vector<int> ngi(temperatures.size(), -1);
        stack<int> st;
        st.push(0);
        for(int i=1; i<temperatures.size(); i++){
            while(!st.empty() && temperatures[st.top()] < temperatures[i]){
                ngi[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        vector<int> answer(temperatures.size(), 0);
        for(int i=0; i<temperatures.size(); i++){
            answer[i] = (ngi[i] - i > 0 ? ngi[i] - i : 0);
        }

        return answer;
    }
};