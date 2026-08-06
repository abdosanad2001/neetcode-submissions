class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //T=O(N); space=O(N)
        int maxL=0;
        unordered_set<int> mySet(nums.begin(),nums.end());
        for(int num: nums){
            if(!mySet.count(num-1)){
                int currentNum=num;
                int currentStreak=1;
                while(mySet.count(currentNum+1)){
                    currentNum++;
                    currentStreak++;
                }
                maxL=max(maxL, currentStreak);
            }

            
        }   
        return maxL;
    }
};
