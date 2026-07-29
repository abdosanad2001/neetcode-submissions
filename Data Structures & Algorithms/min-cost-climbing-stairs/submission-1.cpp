class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        //dp[i]=min cost to reach to the top(n th index)
        //dp[n-1]=cost for 1 step 
        //d[n-2]=cost for 2 step
        int n=cost.size();
        if(n==0){return 0;}
        if(n==1){return 0;}
        vector<int> dp(n+1);
        dp[0]=0;
        dp[1]=0;
        for(int i=2;i<=n;i++){
            dp[i]+=min(dp[i-1]+cost[i-1],dp[i-2]+cost[i-2]);
        }
        return dp[n];
    }
};
