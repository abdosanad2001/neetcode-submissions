class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Time Complexity  : O(N + M log M) ==O(nLogn)
        // N = nums.size() and M = number of unique elements.
        //create a hashmap to calculte frequency of all elements
        unordered_map<int,int> freqMap;
        for(int num : nums){
            freqMap[num]++;
        }
        
        priority_queue<pair<int,int>> pq;//max_heap 
        for(auto& entry: freqMap){
            pq.push({entry.second,entry.first});//O(log(M))
        }
        vector<int> res;
        for(int i=0;i<k;i++){
            res.push_back((pq.top().second));
            pq.pop();//O(log(M))
        }
        return res;










    }
};
