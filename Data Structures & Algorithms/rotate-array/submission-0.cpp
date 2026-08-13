class Solution {
public:
    //T=O(n);space=O(n)
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> new_nums(n);
        for(int i=0;i<n;i++){
            int new_i=i+k;
            if(new_i>=n) new_i=new_i%n;
            new_nums[new_i]=nums[i];
        }
        nums=new_nums;
    }
};