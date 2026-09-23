class Solution {
public:
    bool canJump(vector<int>& nums) {
        //time=O(n^2);space=O(n)//dp
        int n=nums.size();
        vector<bool> dp(n,false);
        dp[0]=true;
        for(int i=0;i<n;i++){
            int max_jump=min(n-1,i+nums[i]);
            for(int j=i+1;j<=max_jump;j++){
                
                if(dp[i]) {
                    dp[j]=true;
                }
            }
        }
        return dp[n-1];
    }
};
