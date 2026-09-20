class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<bool> zero_rows(n,false);
        vector<bool> zero_cols(m,false);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0) {
                    zero_rows[i]=true;
                    zero_cols[j]=true;
                }
            }
        }

        for(int i=0;i<n;i++){
            if(zero_rows[i]) {
                for(int j=0;j<m;j++){
                    matrix[i][j]=0;
                }
            }
            
        }

        for(int j=0;j<m;j++){
            if(zero_cols[j]){
                for(int i=0;i<n;i++){
                    matrix[i][j]=0;
                }
            }
        }

        
    }
};
