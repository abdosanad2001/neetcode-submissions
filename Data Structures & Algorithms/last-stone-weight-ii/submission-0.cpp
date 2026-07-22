class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n=stones.size();
        int sum=0;
        for(int s :stones){
            sum+=s;
        }
        
        vector<vector<int>> dp(n,vector<int>((sum/2)+1,0));
        for(int i=0;i<n;i++){
            dp[i][0]=0;
        }
        for(int j=0;j<=sum/2;j++){
            if(j>=stones[0])
            dp[0][j]=stones[0];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=sum/2;j++){
                if(j-stones[i]>=0){
                dp[i][j]=max(stones[i]+dp[i-1][j-stones[i]],dp[i-1][j]);
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
                if(dp[i][j]==sum/2) return sum-2*dp[i][j];
            }
        }
        return sum-2*dp[n-1][sum/2];
    }
};