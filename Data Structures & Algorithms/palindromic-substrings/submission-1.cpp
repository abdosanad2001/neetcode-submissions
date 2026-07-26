class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        int length=0;
        vector<vector<bool>> dp(n,vector<bool>(n));
        


        for(int l=n-1;l>=0;l--){
            for(int r=l;r<n;r++){
                dp[l][r]=((r-l<2) || (dp[l+1][r-1]) ) && (s[l]==s[r]);
                if(dp[l][r]){length++;}
            }
        }
        return length;
    }
};
