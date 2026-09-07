class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        //Time complexity = O(R*C);Space complexity = O(R*C)
        vector<vector<int>> v;
        int R=heights.size();
        int C=heights[0].size();
        vector<vector<bool>> pac(R,vector<bool>(C,false));
        vector<vector<bool>> atl(R,vector<bool>(C,false));
        auto dfs_pac = [&](auto self,int r,int c){
            if(r<0 ||r>=R ||c<0 ||c>=C ||pac[r][c]){
                return;
            }
            pac[r][c]=true;
            if(r+1<R && !pac[r+1][c]
            && heights[r][c]<=heights[r+1][c])
            self(self,r+1,c);
            if(r-1>=0 && !pac[r-1][c]
            && heights[r][c]<=heights[r-1][c])
            self(self,r-1,c);
            if(c+1<C && !pac[r][c+1]
            && heights[r][c]<=heights[r][c+1])
            self(self,r,c+1);
            if(c-1>=0 && !pac[r][c-1]
            && heights[r][c]<=heights[r][c-1])
            self(self,r,c-1);
        };

        auto dfs_atl = [&](auto self,int r,int c){
            if(r<0 ||r>=R ||c<0 ||c>=C ||atl[r][c]){
                return;
            }
            atl[r][c]=true;
            if(r+1<R && !atl[r+1][c]
            && heights[r][c]<=heights[r+1][c])
            self(self,r+1,c);
            if(r-1>=0  && !atl[r-1][c]
            && heights[r][c]<=heights[r-1][c])
            self(self,r-1,c);
            if(c+1<C  && !atl[r][c+1]
            && heights[r][c]<=heights[r][c+1])
            self(self,r,c+1);
            if(c-1>=0 && !atl[r][c-1]
            && heights[r][c]<=heights[r][c-1])
            self(self,r,c-1);
        };
        
        //dfs from the edge of pac -> the edge atl
        for(int r=0;r<R;r++){
            if(!pac[r][0]){
                dfs_pac(dfs_pac,r,0);
            }
            if(!atl[r][C-1]){
                dfs_atl(dfs_atl,r,C-1);
            }
        }
        //dfs from the edge of atl -> the edge pac
        for(int c=0;c<C;c++){
            if(!pac[0][c]){
                dfs_pac(dfs_pac,0,c);
            }
            if(!atl[R-1][c]){
                dfs_atl(dfs_atl,R-1,c);
            }
        }

        for(int r=0;r<R;r++){
            for(int c=0;c<C;c++){
                if(pac[r][c] && atl[r][c]){
                    v.push_back({r,c});
                }
            }
        }
        return v;

    }
};
