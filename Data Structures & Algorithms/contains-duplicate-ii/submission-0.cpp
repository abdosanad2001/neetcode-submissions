class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n=nums.size();
        for(int l=0;l<n;l++){
            for(int r=l+1;r<n;r++){
                if((nums[r]==nums[l]) && abs(r-l)<=k) return true;
            }
        }
        return false;
    }
};