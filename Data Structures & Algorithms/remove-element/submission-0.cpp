class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int l=0;
        int r=nums.size()-1;
        //using two pointers technique
        while(l<=r){
            if (nums[l]==val){
                int temp=nums[r];
                nums[r]=nums[l];
                nums[l]=temp;
                r-=1;

            }else{
                l+=1;
            }
        }
        return l;
    }
};