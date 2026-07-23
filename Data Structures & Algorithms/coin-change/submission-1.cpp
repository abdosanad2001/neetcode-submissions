class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
    int const INF=1e6;
    int n=coins.size();
    //long long c sest mieux dans  dp vector
    //mais double (10^301)>long long(10^18)
    vector<vector<long long>> dp(n,vector<long long>(amount+1,INF));
    for(int i=0;i<n;i++){
        dp[i][0]=0;
    }
    for(int j=0;j<=amount;j++){
        if(j-coins[0]>=0 && dp[0][j-coins[0]]!=INF){
            dp[0][j]=1+dp[0][j-coins[0]];
        }
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<=amount;j++){
            //skip or peak
            dp[i][j]=dp[i-1][j];
            if(j-coins[i]>=0 ){
                //count coins number +1 not +coins[i]???
            dp[i][j]=min(1+dp[i][j-coins[i]],dp[i][j]);//meme ligne i
            
            }
            
        }
    }
    int result=dp[n-1][amount];
    return (result>=INF)? -1 :result;
        
    }
};
