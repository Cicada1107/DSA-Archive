class SeatManager {
private:
    vector<bool> reserved;
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    SeatManager(int n) {
        reserved.assign(n+1, false);
        for(int i=1; i<=n; i++){
            minHeap.push(i);
        }
    }
    
    int reserve() {
        int x = minHeap.top();
        reserved[x] = true;
        minHeap.pop();
        return x;
    }
    
    void unreserve(int seatNumber) {
        reserved[seatNumber] = false;
        minHeap.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */