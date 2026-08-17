class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        //T=O(n);space=O(1)
        int n=nums.size();
        int min_length=1e6;
        int l=0,r=0;
        int sum=0;
        while(r<n){
            sum+=nums[r];
            while(sum>=target){
                min_length=min(min_length,r-l+1);
                sum-=nums[l];
                l++;
            }
            r++;
        }
        if (min_length<1e6) return min_length;
        return false;
    }
};