class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int n: nums){
            sum+=n;
        }
        if(sum%2!=0){
            return false;
        }
        vector<vector<int>> dp(n,vector<int>((sum/2)+1));
        for(int i=0;i<n;i++){
            dp[i][0]=0;
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=sum/2;j++){
                if(j-nums[i]>=0){
                dp[i][j]=max((nums[i]+dp[i-1][j-nums[i]]) , dp[i-1][j]);
                }else{
                    dp[i][j]=dp[i-1][j];
                }
                if(dp[i][j]==sum/2) return true;
            }
        }
        return false;
    }
};
