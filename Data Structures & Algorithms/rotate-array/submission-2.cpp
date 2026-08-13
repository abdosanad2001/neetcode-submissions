class Solution {
public:
    //T=O(n);space=O(1)
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        reverse(nums.begin(),nums.end());
        k=k%n;
        int l=0,r=k-1;
        while(l<=r){
            int temp=nums[l];
            nums[l]=nums[r];
            nums[r]=temp;
            l++;
            r--;
        }
        int l2=k,r2=n-1;
        while(l2<=r2){
            int temp=nums[l2];
            nums[l2]=nums[r2];
            nums[r2]=temp;
            l2++;
            r2--;
        }
    }
};