class Solution {
public:
    int prefix(vector<int> v,int j){
        if(v.size()==0) return 0;
        int product=1;
        for(int i=0;i<v.size();i++){
            if(i==j){break;}
            product*=v[i];
        }
        return product;
    }
    int suffix(vector<int> v,int j){
        if(v.size()==0) return 0;
        int product=1;
        for(int i=j+1;i<v.size();i++){
            if(i==j){break;}
            product*=v[i];
        }
        return product;
    }
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            res.push_back(prefix(nums,i)*suffix(nums,i));
        }
        return res;
    }
};
