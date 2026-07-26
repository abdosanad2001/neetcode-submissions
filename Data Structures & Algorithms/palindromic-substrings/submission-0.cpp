class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        //odd
        int length=0;
        if(n==0){return 0;}


        for(int i=0;i<n;i++){
                //odd
                int l=i,r=i;
                while(l>=0 && r<n){
                    if(s[l]==s[r]){
                        length++;
                        l--;
                        r++;
                    }
                    else{
                        break;
                    }

                }
            
            
                
                //even
                l=i,r=i+1;
                while(l>=0 && r<n){
                    if(s[l]==s[r]){
                        length++;
                        l--;
                        r++;
                    }
                    else{
                        break;
                    }

                }
        

}


    return length;
}
};
