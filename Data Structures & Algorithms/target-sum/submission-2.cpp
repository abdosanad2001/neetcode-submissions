class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        for(int num : nums) {
            sum += num;
        }
        int n=nums.size();
        if(abs(target)>sum) return 0;

        vector<vector<int>> dp(n,vector<int>(2*sum+1,0));
        dp[0][sum + nums[0]] += 1;
        dp[0][sum - nums[0]] += 1;//car on a 2 opertaions + et - a la base

        
        for(int i=1;i<n;i++){
            for(int j=0;j<=2*sum;j++){
                int target1=j-nums[i];
                int target2=j+nums[i];
                int ways1 = (target1 >= 0) ? dp[i-1][target1] : 0;
                int ways2 = (target2 <= 2 * sum) ? dp[i-1][target2] : 0;
                
                dp[i][j] = ways1 + ways2;
            }
            
        }
        return dp[n-1][sum+target];




    }
};
