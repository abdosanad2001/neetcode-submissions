class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        //time=O(n*m);space=O(n*m)
        int left=0,right=matrix[0].size()-1;
        int top=0,bottom=matrix.size()-1;
        vector<int> res;
        while(left<=right && top<=bottom){
            int j=left;
            while(j<=right){
                res.push_back(matrix[top][j]);
                j++;
            }
            top++;
            
            int i=top;
            while(i<=bottom){
                res.push_back(matrix[i][right]);
                i++;
            }
            right--;
            
            if(top<=bottom){
                j=right;
                while(j>=left){
                    res.push_back(matrix[bottom][j]);
                    j--;
                }
                bottom--;

            }
            

            if(left<=right){
                 i=bottom;
                while(i>=top){
                    res.push_back(matrix[i][left]);
                    i--;
                }
                left++;
            }
           
        }
        return res;
        
        
    }
};
