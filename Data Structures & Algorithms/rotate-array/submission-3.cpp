class Solution {
public:
    //T=O(n);space=O(1)
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        reverse(nums.begin(),nums.end());
        k=k%n;
        int l=0,r=k-1;
        while(l<=r){
            swap(nums[l],nums[r]);
            l++;
            r--;
        }
        int l2=k,r2=n-1;
        while(l2<=r2){
           swap(nums[l2],nums[r2]);
            l2++;
            r2--;
        }
    }
};