class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //Time=O(n*m);space=o(1)
        int n=matrix.size(),m=matrix[0].size();
        //int l=0,r=n-1,l2=0,r2=m-1;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<m;j++){
                int temp=matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=temp;
            }
        }
        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};
