class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        //Boyer-Moore Majority Vote Algorithm
        //space=O(1) ;T=O(n)
        int n=nums.size();
        int count1=0,count2=0;
        int res1=0,res2=0;
        for(int num: nums){
            if(res1==num) count1++;
            else if(res2==num) count2++;
            else if(count1==0) {
                res1=num;
                count1=1;
            }
            else if(count2==0){
                res2=num;
                count2=1;
            }
            else{
                count1--;
                count2--;
            }
        }

       count1=0;count2=0;
       for(int num: nums){
        if(res1==num){count1++;}
        else if(res2==num){count2++;}
       }
        vector<int> v;
        if(count1>(n/3)) v.push_back(res1);
        if(count2>(n/3) && res2!=res1) v.push_back(res2);
        return v;
        
    }
};