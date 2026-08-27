class MedianFinder {
    //Space=O(N)
private:
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>,greater<int>> min_heap;
    

public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {//O(LogN)
        if(max_heap.empty() || max_heap.top()>=num ) {
            max_heap.push(num);
        }
        else{
            min_heap.push(num);
        }

        if(max_heap.size()>min_heap.size()+1){
            min_heap.push(max_heap.top());
            max_heap.pop();
        }else if(max_heap.size()<min_heap.size()){
            max_heap.push(min_heap.top());
            min_heap.pop();
        }

    }
    
    double findMedian() {//O(1)
        int t_size=max_heap.size()+min_heap.size();
        if(t_size%2==0){
            int temp1=max_heap.top();
            int temp2=min_heap.top();
            return (temp1+temp2)/2.0;
        }
        else{
            int temp=max_heap.top();
            return temp;
        }
    }
};