class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int const INF=1e6;
        vector<int> min_dp(n);
        vector<int> max_dp(n);

        max_dp[0]=nums[0];
        min_dp[0]=nums[0];
        int ans=nums[0];
        for(int i=1;i<n;i++){
            
            max_dp[i]=max({nums[i]*max_dp[i-1],nums[i],min_dp[i-1]*nums[i]});
            min_dp[i]=min({nums[i]*min_dp[i-1],nums[i],nums[i]*max_dp[i-1]});
            
            ans =max(ans,max_dp[i]);
        }
        return ans;
    }
};
