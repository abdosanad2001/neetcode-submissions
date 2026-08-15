class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //T=O(n);Space=O(1)
        int n=s.size();
        int l=0,r=0;
        int res=0;
        unordered_set<char> mySet;
        while(r<n){
            if(mySet.count(s[r])){
                mySet.erase(s[l]);
                l++;
            }else{
                mySet.insert(s[r]);
                r++;
            }
            res=max(r-l,res);
            
        }
        return res;
    }
};
