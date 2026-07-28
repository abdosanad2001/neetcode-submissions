class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        vector<int> A(n+2,1);
        for(int i=0;i<n;i++){
            A[i+1]=nums[i];//[1,nums[0],nums[2],..,nums[n-1],1]
        }
        vector<vector<int>> dp(n+2,vector<int>(n+2));
        for(int len=1;len<=n;len++){
            for(int l=1;l<=n-len+1;l++){
                int r=l+len-1;
                dp[l][r]=0;//por maximiser
                for(int i=l;i<=r;i++){
                    int cost=A[l-1]*A[i]*A[r+1]+
                    dp[l][i-1]+dp[i+1][r];
                    dp[l][r]=max(dp[l][r],cost);
                }
            }
        }
        return dp[1][n];//max profit de first baloon (1) to last baloon (n)
    }
};
