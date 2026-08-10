class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //T=O(n);Space=O(n)
        unordered_map<int,int> prefCounts;
        int n=nums.size();
        prefCounts[0]=1;
        int count=0;
        int curSum=0;
        for(int num: nums){
            curSum+=num;
            count=count+prefCounts[curSum-k];
            prefCounts[curSum]++;
        }
        return count;

    }
};