class TrieNode{
public:
    vector<TrieNode*> children;

    TrieNode(){
        this->children = vector<TrieNode*> (2);
        this->children[0] = this->children[1] = nullptr;
    }
};

class Solution {
private:
    void insert(int k, TrieNode* root){
        TrieNode* curr = root;

        for(int i=30; i>=0; i--){
            int bit = (k>>i) & 1;
            
            if(!curr->children[bit]){
                curr->children[bit] = new TrieNode();
            }

            curr = curr->children[bit];
        }
    }

    int maxXor(int x, TrieNode* root){
        TrieNode* curr = root;

        int result = 0;

        for(int i=30; i>=0; i--){
            int reqd_bit = !((x>>i) & 1);
            if(!curr->children[reqd_bit]){
                result |= (0<<i);
                curr = curr->children[!reqd_bit];
            }else{
                result |= (1<<i);
                curr = curr->children[reqd_bit];
            }
        }

        return result;
    }

public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), q = queries.size();
        vector<int> ans(q);

        sort(nums.begin(), nums.end());
        for(int i=0; i<q; i++){
            queries[i].push_back(i);
        }
        sort(queries.begin(), queries.end(), [](const vector<int> &a, const vector<int> &b){
            return a[1] < b[1];
        });

        TrieNode* root = new TrieNode();
        //MSB -> LSB :: top -> Bottom (For the greedy approach to work)
        int ind = 0;

        for(auto &query: queries){
            int x = query[0], m = query[1], i = query[2];

            while(ind < n && nums[ind] <= m){
                insert(nums[ind], root);
                ind++;
            }

            int res = (ind == 0 ? -1 : maxXor(x, root));
            ans[i] = res;
        }

        return ans;
    }
};