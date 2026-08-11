class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int l1=m+n-1;
        int l2=n-1;
        int l3=m-1;
        while(l3>=0 && l2>=0){
            if(nums2[l2]<nums1[l3]){
                nums1[l1]=nums1[l3];
               l3--;
            }
            else{
                nums1[l1]=nums2[l2];
                l2--;
            }
            l1--;
        }
        while(l2>=0){
            nums1[l1]=nums2[l2];
            l2--;
            l1--;
        }
            
    }
        
    
};