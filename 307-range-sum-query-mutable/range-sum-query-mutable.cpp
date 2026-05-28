class NumArray {
private:
    vector<int> segTree, nums;
    int n;

    void buildTree(int i, int l, int r){
        if(l == r){
            segTree[i] = nums[l];
            return;
        }

        int mid = l + (r-l)/2;
        buildTree(2*i+1, l, mid);
        buildTree(2*i+2, mid+1, r);

        segTree[i] = segTree[2*i+1] + segTree[2*i+2];
    }

    void updateST(int idx, int val, int i, int l, int r){
        if(l == r){
            segTree[i] = val;
            return;
        }

        int mid = l + (r-l)/2;
        if(idx <= mid){
            updateST(idx, val, 2*i+1, l, mid);
        }else{
            updateST(idx, val, 2*i+2, mid+1, r);
        }
        
        segTree[i] = segTree[2*i+1] + segTree[2*i+2];
    }

    int rangeSum(int i, int tl, int tr, int l, int r){
        if(tl>r || tr<l) return 0;
        if(l<=tl && r >= tr) return segTree[i];

        int tmid = tl + (tr-tl)/2;
        return rangeSum(2*i+1, tl, tmid, l, r) + rangeSum(2*i+2, tmid+1, tr, l, r);
    }

public:
    NumArray(vector<int>& nums) {
        this->nums = nums;
        this->n = nums.size();
        segTree.assign(4*n, 0);

        buildTree(0, 0, n-1);
    }
    
    void update(int index, int val) {
        updateST(index, val, 0, 0, n-1);
    }
    
    int sumRange(int left, int right) {
        return rangeSum(0, 0, n-1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */