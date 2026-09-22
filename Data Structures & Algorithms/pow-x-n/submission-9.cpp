class Solution {
public:
    double power(double x,long long n){
            //Time=O(logn);space=O(1)
            if(n==0) return 1.0;
            if(n==1) return x;
            //if(n==2) return x*x;
            double half=power(x,n/2);
            if(n>=2 && n%2==0){
                return half*half;
            }else{
                return x*half*half;
            }
        }
    double myPow(double x, int n) {
        double res=1;
        if(x==0.0) return 0;
        if(n==0) return 1;
        
        if(n>=1){
            res=power(x,n);
        }
        if(n<0){
            res=power((1/x),-n);
        }
        return res;
        
    }
};
