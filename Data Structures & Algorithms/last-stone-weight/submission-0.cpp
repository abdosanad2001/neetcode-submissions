class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        //time=O(N)+O(Nlog(N)) = O(NLog(N));space=O(n)
        priority_queue<int> max_heap;
        for(int st:stones){
            max_heap.push(st);
        }
        int x;
        int y;
        while(max_heap.size()>1){
            if(!max_heap.empty()){
            x=max_heap.top();
            max_heap.pop();
            y=max_heap.top();
            max_heap.pop();
            if(y<x){ 
                max_heap.push(x-y);
            }
          }
        }
       return max_heap.empty() ? 0 : max_heap.top();

    }
};
