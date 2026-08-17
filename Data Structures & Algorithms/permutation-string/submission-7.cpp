class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        //T=O(26*n2)=O(n2);space=O(1)
        int n1=s1.size();
        int n2=s2.size();
        if(n1>n2) return false;
        unordered_map<char,int> freq1;
        unordered_map<char,int> freq2;

        for(int i=0;i<n1;i++){
            freq1[s1[i]]++;
        }

        int l=0,r=0;
        while(r<n2){
            if(freq1.count(s2[r])==0) {
                freq2.clear();
                l=r+1;
                }
            else{
                freq2[s2[r]]++;

                if(r-l+1>n1){
                   freq2[s2[l]]--;
                   if(freq2[s2[l]]==0) freq2.erase(s2[l]);
                   l++;
                }
            if(freq1==freq2) return true;
            
            
            }
            r++;
        
       
        }
        return false;
            
    }

    
};
