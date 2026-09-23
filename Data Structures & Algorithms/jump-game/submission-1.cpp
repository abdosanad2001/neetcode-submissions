class Solution {
public:
    bool canJump(vector<int>& nums) {
        //greedy
        //time=O(n);space=O(1)
        int n=nums.size();
        int goal=n-1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]+i>=goal){
                goal=i;
            }
            
        }
        return goal==0;
    }
};
