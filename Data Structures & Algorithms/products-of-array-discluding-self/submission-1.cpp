class Solution {
public:
   
    
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
       
        int product_l=1;
        int product_r=1;
        vector<int> res1;
        for(int i=0;i<n;i++){
            product_l=(i>0) ? product_l*nums[i-1]:1;
            res1.push_back(product_l);

        }
        vector<int> res2;
        for(int i=n-1;i>=0;i--){
            product_r=(i<n-1) ? product_r*nums[i+1]:1;
            res2.push_back(product_r);
        }
        //reverse suffix 
        reverse(res2.begin(),res2.end());
        
        vector<int> res;
        for(int i=0;i<n;i++){
            res.push_back(res1[i]*res2[i]);
        }
        
        return res;
        
    }
};
