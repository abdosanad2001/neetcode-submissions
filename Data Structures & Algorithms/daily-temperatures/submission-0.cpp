class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        //Time=O(n) || space=O(n)
        vector<int> res(n,0);
        stack<pair<int,int>> dec_stack;
        for(int i=0;i<n;i++){
            while(!dec_stack.empty() &&
            temperatures[i]>dec_stack.top().first){
                int prevTemp=dec_stack.top().first;
                int prevIndex=dec_stack.top().second;
                dec_stack.pop();

                res[prevIndex]=i-prevIndex;
                
                }
                dec_stack.push({temperatures[i],i});
            }{
                
                
            



        }
               
                

        
        return res;

    }
};
