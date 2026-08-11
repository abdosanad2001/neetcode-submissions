class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //T=O(2n)=O(n);Space=O(1)
        int n=nums.size();
        if(n==0) return 0;
        int l=1,r=1;
        while(r<n){
            if(nums[r]!=nums[r-1]){
                nums[l]=nums[r];
                l+=1;
            }
            r+=1;
        }
        return l;
    }
};