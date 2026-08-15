class Solution {
public:
    int characterReplacement(string s, int k) {
        //T=O(26n)=O(n); space=O(1)
     int n=s.size();
     int l=0,r=0;
     int res=0;
     vector<int> freq(26,0);
     while(r<n){
        freq[s[r] - 'A']++;
        while( (r-l+1)-*max_element(freq.begin(),freq.end() ) >k){
            freq[s[l]-'A']--;
            l++;
        }

        
        res=max(res,r-l+1);
        r++;
     }
    return res;
    
    
    
    }
};
