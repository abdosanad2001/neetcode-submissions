class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        if(n==0 || s[0]=='0'){ return 0;}
        vector<int> dp(n+1,0);
        dp[0]=1;//empty[]
        dp[1]=1;//first character!=0
        for(int i=2;i<=n;i++){
            int single_digit=s[i-1]-'0';
            if(single_digit>=1 && single_digit<=9){
            dp[i]+=dp[i-1];
            }
            int double_digit=single_digit+10*(s[i-2]-'0');
            if(double_digit>=10 && double_digit<=26){
            dp[i]+=dp[i-2];
            }
        }
        return dp[n];

    }

};
