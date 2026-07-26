class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,0));

        for(int l=n-1;l>=0;l--){
            for(int r=l;r<n;r++){
                if(s[l]==s[r]){
                    if(r-l==0) dp[l][r]=1;
                    else dp[l][r]=2+dp[l+1][r-1];
                }else
                dp[l][r]=max(dp[l][r-1],dp[l+1][r]);
            }
        }
        return dp[0][n-1];
    }
};