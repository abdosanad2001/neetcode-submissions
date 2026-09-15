class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(),n=matrix[0].size();
        int l1=0,r1=m-1,l2=0,r2=n-1;
        
        int row=-1;
        while(l1<=r1){
            int mid1=l1+(r1-l1)/2;
            
            if(matrix[mid1][n-1]<target){
                l1=mid1+1;
            }else if(matrix[mid1][0]>target){
                r1=mid1-1;
            }else{
                row=mid1;
                break;
            }
        }
        if(row==-1) return false;

        while(l2<=r2){
            int mid2=l2+(r2-l2)/2;
            if(matrix[row][mid2]<target){
                l2=mid2+1;
            }else if(matrix[row][mid2]>target){
                r2=mid2-1;
            }else if(matrix[row][mid2]==target){
                return true;
            }
            
        }
        return false;
        
    }
};
