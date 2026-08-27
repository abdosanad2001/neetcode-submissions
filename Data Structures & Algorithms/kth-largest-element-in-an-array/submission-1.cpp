class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //Time=O(NLogK);spce=O(k)
        priority_queue<int> max_heap;
        for(int num:nums){
            max_heap.push(num);
        }
        int largest_k=0;
        while(k){
            largest_k=max_heap.top();
            max_heap.pop();
            k--;

        }
        return largest_k;



        
    }
};
