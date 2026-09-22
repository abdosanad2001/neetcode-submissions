class Solution {
public:
    bool isHappy(int n) {
        
        auto sumDigit=[&](int nb)->int{
            int sum=0;
            while(nb>0){
                sum+=(nb%10)*(nb%10);
                nb=nb/10;
            }
            return sum;
            
        };
        unordered_set<int> seen;
        seen.insert(n);
        while(n>1){
            n=sumDigit(n);
            if(seen.count(n)==0){
                seen.insert(n);
            }
            else return false;
            
        }
        return true;
        
        
        
        
    }
};
