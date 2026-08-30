#define ll long long
const ll MOD = 1e9 + 7;

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();

        // nsi array(including equal element on the right)
        stack<int> st;
        vector<int> nsi(n, n);
        for(int i=0; i<n; i++){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                nsi[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        
        // psi array(excluding equal elements on the left to avoid double counting)
        stack<int> st2;
        vector<int> psi(n, -1);
        for(int i=n-1; i>=0; i--){
            while(!st2.empty() && arr[st2.top()] > arr[i]){
                psi[st2.top()] = i;
                st2.pop();
            }
            st2.push(i);
        }

        // for(auto &it: nsi) cout<<it<<" ";
        // cout<<endl;
        // for(auto &it: psi) cout<<it<<" ";
        // cout<<endl;


        // ans += element * number of subarrays it is min of
        ll ans = 0;
        for(int i=0; i<n; i++){
            // int l = (psi[i] == -1 ? 0 : psi[i] + 1);
            // int r = (nsi[i] == n ? n-1 : nsi[i] - 1);
            int r = nsi[i] - 1, l = psi[i]+1;
            ll m = (i-l+1) * (r-i+1);
            ans = (ans + (m * arr[i]) % MOD) % MOD;
            // cout<<ans<<" ";
        }

        return ans;
    }
};