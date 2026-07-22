class Solution {
public:
    int f(string strs,int n){
        char target=n+'0';
        int count=0;
        for(int j=0;j<strs.size();j++){
            if(target==strs[j]) {count++;}
        }
        return count;
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int k=strs.size();
        vector<vector<vector<int>>> dp(k, vector<vector<int>>(m+1, vector<int>(n+1,0)));
        for(int i=0;i<k;i++){
            dp[i][0][0]=0;
        }
        //for(int j=0;j<=m;j++){
        //    dp[0][j][0]=0;
        //}
        //for(int l=0;l<=n;l++){
        //   dp[0][0][l]=0;
        //}
        for(int i=0;i<k;i++){
            for(int j=0;j<=m;j++){
                for(int l=0;l<=n;l++){
                    if((j-f(strs[i],0)>=0) && (l-f(strs[i],1))>=0){
                        if(i==0){
                             dp[i][j][l]=1;continue;
                        }else
                    dp[i][j][l]=max(1+dp[i-1][j-f(strs[i],0)][l-f(strs[i],1)],dp[i-1][j][l]);
                    }else{
                        dp[i][j][l]=(i==0)? 0: dp[i-1][j][l];
                    }
                }
            }
        }
        return dp[k-1][m][n];
    }
};