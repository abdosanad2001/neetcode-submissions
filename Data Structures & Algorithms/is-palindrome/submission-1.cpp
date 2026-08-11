class Solution {
public:
    bool isPalindrome(string s) {
        string new_s="";
        for(int i=0;i<s.size();i++){
            s[i]=tolower(s[i]);
            if(!isalnum(s[i])) continue;
            else new_s+=s[i];
        }

        int n=new_s.size();
        int l=0,r=n-1;
        while(l<=r){
            if(new_s[l]!=new_s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};
