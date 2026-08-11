class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int l1=0,l2=0;
        int n=word1.size(),m=word2.size();
        //T=O(n+m);space=O(n+m)
        string new_word="";
        while(l1<n && l2<m){
            new_word+=word1[l1];
            new_word+=word2[l2];
            l1++;
            l2++;
        }
        if(n>m){
            l1=l2;
            while(l1<n){
                new_word+=word1[l1];
                l1++;
            }
            
        }
        if(n<m){
            l2=l1;
            while(l2<m){
                new_word+=word2[l2];
                l2++;
            }
            
        }
        return new_word;

    }
};