class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        int n = heights.size();
        for(int i=0; i<n-1; i++){
            int climb = heights[i+1] - heights[i];
            if(climb <= 0) continue;
            if(ladders > 0){
                ladders--;
                minHeap.push(climb);
            }else{
                if(minHeap.empty() || climb < minHeap.top()){
                    bricks-=climb;
                }else{
                    bricks-=minHeap.top();
                    minHeap.pop();
                    minHeap.push(climb);
                }
                if(bricks < 0) return i;
            }
        }

        return n-1;
    }
};