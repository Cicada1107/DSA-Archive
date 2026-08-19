class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> hash;
        int n = fruits.size();
        int i=0, ans = 0;
        for(int j=0; j<n; j++){
            hash[fruits[j]]++;
            while(hash.size() > 2){
                hash[fruits[i]]--;
                if(hash[fruits[i]] == 0) hash.erase(fruits[i]);
                i++;
            }
            ans = max(j-i+1, ans);
        }

        return ans;
    }
};