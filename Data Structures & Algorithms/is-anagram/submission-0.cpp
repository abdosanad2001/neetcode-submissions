class Solution {
public:
    bool isAnagram(string s, string t) {
        int n=s.size();
        int m=t.size();
        if(n!=m){return false;}
        unordered_map<char,int> myMap;
        for(int i=0;i<n;i++){
            myMap[s[i]]++;
        }
        for(int i=0;i<m;i++){
            if(myMap.contains(t[i]) && myMap[t[i]]>0){
                myMap[t[i]]--;
            }
            else{

                return false;          
            }
            
        }
        return true;
        
    }
};
