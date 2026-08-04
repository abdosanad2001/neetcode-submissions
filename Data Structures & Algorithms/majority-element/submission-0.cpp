class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> myMap;
        for(int num: nums){
            
            myMap[num]++;
            if(myMap[num]>(n/2)){
                    return num;
            }
            
        }
    }
};