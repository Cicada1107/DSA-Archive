// Approach 1: Graph

class Solution {
public:
    int minSplitMerge(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        if(nums1 == nums2) return 0;

        queue<vector<int>> q;
        set<vector<int>> s;
        q.push(nums1);
        s.insert(nums1);

        int steps = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                vector<int> curr = q.front();
                q.pop();
                
                //debug
                // for(auto &it: curr) cout<<it<<" ";
                // cout<<endl;

                if(curr == nums2) return steps;

                // generating the next states (nodes)
                for(int l=0; l<n; l++){
                    for(int r=l; r<n; r++){
                        vector<int> sub(curr.begin()+l, curr.begin()+r+1);
                        vector<int> temp(curr.begin(), curr.begin()+l);
                        temp.insert(temp.end(), curr.begin()+r+1, curr.end());
                        for(int i=0; i<temp.size(); i++){
                            vector<int> newState = temp;
                            newState.insert(newState.begin()+i, sub.begin(), sub.end());
                            if(s.find(newState) != s.end()) continue;
                            s.insert(newState);
                            q.push(newState);
                        }
                    }
                }
            }
            steps++;
        }

        return -1;
    }
};