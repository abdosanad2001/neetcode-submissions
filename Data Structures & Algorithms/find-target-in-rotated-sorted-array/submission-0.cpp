class Solution {
public:
    int search(vector<int>& nums, int target) {
        //Time=O(LognN);space=O(1)
        
        int n=nums.size();
        auto findPivot=[&]()->int{
            int l=0,r=n-1;
            int ans=0;
            while(l<=r){
                int mid=l+(r-l)/2;
                if(nums[mid]<=nums[n-1]){
                    r=mid-1;
                    ans=mid;
                } 
                else l=mid+1;
            }
            return ans;
        };
        int pivot=findPivot();
        int l=pivot,r=n-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]<target){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        if(pivot>0){
            int l1=0,r1=pivot-1;
            while(l1<=r1){
                int mid1=l1+(r1-l1)/2;
                if(nums[mid1]==target) return mid1;
                else if(nums[mid1]<target){
                    l1=mid1+1;
                }
                else{
                    r1=mid1-1;
                }
            }
        }
        return -1;
    }
};
