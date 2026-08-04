class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int res=0;
        int count=0;
        //using Boyer-Moore Voting Algorithm
        for(int i=0;i<n;i++){
            if(count == 0){res=nums[i];}
            count+=((nums[i]==res)? 1 : -1);
        }
        return res;
            
        
    }
};