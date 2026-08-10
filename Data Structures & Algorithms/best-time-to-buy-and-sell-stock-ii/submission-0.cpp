class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=0;
        int sell=0;
        int profit=0;
        for(int i=0;i<prices.size()-1;i++){
            if(prices[i+1]>prices[i]){
                buy=prices[i];
                sell=prices[i+1];
                profit+=sell-buy;
            }
            
            
        }
        return profit;
    }
};