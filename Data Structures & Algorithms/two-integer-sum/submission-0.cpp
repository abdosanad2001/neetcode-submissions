class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> myMap;
        for(int i=0;i<nums.size();i++){
            if(!myMap.contains((target-nums[i]))){
                myMap[nums[i]]=i;
            }
            else{
                return {myMap[target-nums[i]],i};
            }
        }
    }
};
