class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //T=O(n);space=O(1)
        int n=prices.size();
        int l=0,r=0;
        int res=0;
        while(r<n){
                if(prices[r]>prices[l]){
                res=max(res,prices[r]-prices[l]);
                }else{
                    l=r;
                }
            r++;
        }
        return res;

    }
};
