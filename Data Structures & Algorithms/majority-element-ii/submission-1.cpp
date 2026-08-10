class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        //T=O(n)
        //space=O(n) using a hashmap
        int n=nums.size();
        unordered_map<int,int> freqMap;
        for(int num: nums){
            freqMap[num]++;
        }
        vector<int> v;
        for(const auto& pair:freqMap){
            int key=pair.first;
            int value=pair.second;
            if(value>(n/3))
            v.push_back(key);
        }

        return v;
    }
};