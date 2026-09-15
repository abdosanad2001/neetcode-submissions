class Solution {
public:
    int findMin(vector<int> &nums) {
        //Time=O(LogN);space=O(1)
        int n=nums.size();
        int l=0,r=n-1,ans=0;
        auto findPivot=[&]()->int{
            while(l<=r){
                int mid=l+(r-l)/2;
                if(nums[mid]<=nums[n-1]){
                    r=mid-1;
                    ans=mid;}
                else{
                    l=mid+1;}
            }
            return ans; 
        };

        int pivot=findPivot();

        return nums[pivot];
    }
};
