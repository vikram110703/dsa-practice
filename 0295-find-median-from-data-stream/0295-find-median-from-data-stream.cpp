class MedianFinder {
public:
    // [1 2 3]->maxHeap and min heap<-[5,7,9,10] will store in this way 
    priority_queue<int>maxHeap;
    priority_queue<int,vector<int>,greater<int>>minHeap;

    MedianFinder() {    
    }
    //try to add low val in min heap and high in max heap
    
    void addNum(int num) {
        maxHeap.push(num);
        minHeap.push(maxHeap.top());
        maxHeap.pop();

        if(minHeap.size()>maxHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if(maxHeap.size()>minHeap.size()){
            return maxHeap.top();
        }
        return double((maxHeap.top()+minHeap.top())/2.0);
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */