class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        
        vector<vector<int>> v;
        for(int i=0;i<n;i++){
        int l=i+1,r=n-1,m=i;
        if(i>0 && nums[i]==nums[i-1]) continue;
        while(l<r && m<n-2){
            if(nums[l]+nums[r]==-nums[m]){
                v.push_back({nums[l],nums[m],nums[r]});
                while (l < r && nums[l] == nums[l + 1]) l++;
                    while (l < r && nums[r] == nums[r - 1]) r--;
                    
                    l++;
                    r--;
            }
            else if(nums[l]+nums[r]<-nums[m]){
                l+=1;
            }
            else{
                r-=1;
            }
        }
        }
        return v;
    }
};
