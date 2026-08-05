class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //T=O(n+mlogm) space=O(n):hashmap and vector
        unordered_map<int,int> myMap;
        for(int num : nums){
            myMap[num]++;
        }
        vector<pair<int,int>> freqVector;
        for(auto& entry: myMap){
            freqVector.push_back({entry.second,entry.first});
        }
        //O(mlogm) :m=number of unique numbers not the size()
        sort(freqVector.rbegin(),freqVector.rend());

        vector<int> result;
        for(int i=0;i<k;i++){
            result.push_back(freqVector[i].second);
        }
        return result;
        


        
        
    }
};
