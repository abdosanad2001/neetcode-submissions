class Solution {
public:
    //T=O(n)=O(n) ;space= O(1) 
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    int l=0,r=arr.size()-1;
    while(r-l+1>k){
       if(abs(arr[l]-x)>abs(arr[r]-x)){
        l++;
       }else{
        r--;
       }
    }
    return vector<int>(arr.begin()+l,arr.begin()+l+k);
        
    }
};