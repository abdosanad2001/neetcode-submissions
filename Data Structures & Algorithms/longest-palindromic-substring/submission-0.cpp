class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        int maxL=0;
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        for(int l=n-1;l>=0;l--){
            for(int r=l;r<n;r++){
                dp[l][r]= ((r-l<2) || dp[l+1][r-1]) && (s[l]==s[r]);
                if(dp[l][r]){maxL=max(maxL,r-l+1);}
            }
        }

        for(int l=n-1;l>=0;l--){
            for(int r=l;r<n;r++){
            if(r-l+1==maxL && dp[l][r]) return s.substr(l,r-l+1);
            }
            
        }
        return "";
    }
    
};
