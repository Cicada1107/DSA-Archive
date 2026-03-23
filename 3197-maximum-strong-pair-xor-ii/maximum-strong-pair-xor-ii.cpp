#define ll long long

// sliding window for O(n) mein finding the pairs where the given condition is true
// bit trie for O(log b) (b = number of bits) mein finding the max xor of a segment
// log 32 is comnstant so we get O(n.32) = o(n) solution.
// also, we will sort the array so that the sliding window can be implemented with ease, assuming y > x
// hence O(n log n) is the final complexity

class TrieNode{
public:
    TrieNode* child[2];
    int count;
    
    TrieNode(){
        child[0] = nullptr;
        child[1] = nullptr;
        count = 0;
    }
};

class BitTrie{
private:
    TrieNode* root;

public:
    BitTrie(){
        root = new TrieNode();
    }

    void addNum(int num){
        TrieNode* node = root;
        for(int i=20; i>=0; i--){
            int bit = (num>>i) & 1;
            if(node->child[bit] == nullptr){
                node->child[bit] = new TrieNode();
            }
            node = node->child[bit];
            node->count++;
        }
    }

    void deleteNum(int num){
        TrieNode* node = root;
        for(int i=20; i>= 0; i--){
            int bit = (num>>i) & 1;
            if(node->child[bit] == nullptr){
                return;
            }
            node = node->child[bit];
            node->count--;
        }
    }

    int maxXor(int num){
        TrieNode* node = root;
        int ans = 0;
        for(int i=20; i>=0; i--){
            int bit = (num>>i) & 1;
            if(node->child[1-bit] != nullptr && node->child[1-bit]->count > 0){
                ans |= 1<<i;
                node = node->child[1-bit];
            }
            else if(node->child[bit] != nullptr && node->child[bit]->count > 0){
                node = node->child[bit];
            }
            else{
                break;
            }
        }
        return ans;
    }
};

class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        int l = 0;
        BitTrie trie;
        for(int r=0; r<n; r++){
            // shrink window if invalid
            while(nums[r] > 2*nums[l]){
                trie.deleteNum(nums[l]);
                l++;
            }

            // expand window
            trie.addNum(nums[r]);
            ans = max(ans, trie.maxXor(nums[r]));
        }

        return ans;
    }
};