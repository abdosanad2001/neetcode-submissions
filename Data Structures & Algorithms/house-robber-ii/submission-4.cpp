class Solution {
public:
    int rob(vector<int>& nums) {
        //dp[i]=max amount robbed from 0 th to ith house
        int n=nums.size();
        if(n==0){return 0;}//[]
        if(n==1){return nums[0]; }//[..]
        if(n==2){return max(nums[0],nums[1]);}
        vector<unsigned int> dp(n,0);
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        int max1=0;
        for(int i=2;i<n-1;i++){//not rob last house
           
            dp[i]=max(dp[i-1],nums[i]+dp[i-2]);
            max1=dp[i];
        }
        int max2=0;
        dp[0]=0;
        dp[1]=nums[1];
        for(int i=2;i<n;i++){//not rob first house
           
            dp[i]=max(dp[i-1],nums[i]+dp[i-2]);
            max2=dp[i];
        }
        return max(max1,max2);
        
    }
};
