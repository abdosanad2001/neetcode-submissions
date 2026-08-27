class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //Time=O(nlogn) ;space=o(1)
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size();i++){
            return nums[nums.size()-1-(k-1)];
        }
    }
};
