class Solution {
public:
    vector<vector<string>> res;
    vector<string> path;
    vector<vector<bool>> dp;

    void backtrack(string s,int start){
        if(start==s.size()){
            res.push_back(path);
            return;
        }
        for(int end=start;end<s.size();end++){
            if(dp[start][end]){
                path.push_back(s.substr(start,end-start+1));//chose
                backtrack(s,end+1);//explore
                path.pop_back();//unchose
            }
        }
    }

    
    vector<vector<string>> partition(string s) {
       int n=s.size();
       dp.assign(n, vector<bool>(n, false));
       for(int l=n-1;l>=0;l--){
       for(int r=l;r<n;r++){
            dp[l][r]=((r-l<2) ||dp[l+1][r-1]) &&(s[l]==s[r]);
           
           
        }
       }
       backtrack(s,0);
       return res;
    }


    
};
