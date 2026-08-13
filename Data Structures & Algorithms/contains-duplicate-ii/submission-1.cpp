class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        //T=O(n);space=O(1)
        unordered_set<int> window;
        int n=nums.size();
        int l=0,r=0;
        while(r<n){
            if(abs(r-l)>k){
                window.erase(nums[l]);
                l++;
            }else{
                if(window.count(nums[r])) return true;
                else {
                    window.insert(nums[r]);
                    r++;
                    }

            }
            
        }
        return false;
    }
};