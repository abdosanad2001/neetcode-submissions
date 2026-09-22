class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        //time=O(n);space=O(1)
        long long nb=0;
        for(int i=0;i<digits.size();i++){
            nb+=digits[i];
            if(i<digits.size()-1)
            nb*=10;
        }
        vector<int> res;
        long long new_nb=nb+1;
        while(new_nb>0){
            res.push_back(new_nb%10);
            new_nb/=10;
        }
        reverse(res.begin(),res.end());
        return res;
        
    }
};
