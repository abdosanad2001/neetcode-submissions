class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        const int INF=2147483647;
        int R=grid.size(),C=grid[0].size();
        //Time=O(R*C);space=O(R*C)
        vector<vector<bool>> visited(R,vector<bool>(C,false));
        int dr[]={-1,1,0,0},dc[]={0,0,-1,1};

        queue<pair<int,int>> q;
        for(int r=0;r<R;r++){
            for(int c=0;c<C;c++){
                if(grid[r][c]==0){
                    q.push({r,c});
                }
            }
        }

        while(!q.empty()){
                auto [r,c]=q.front();
                q.pop();
                for(int i=0;i<4;i++){   
                    int nr=r+dr[i],nc=c+dc[i];
                    if(nr>=0 && nr<R && nc>=0 &&nc<C && 
                    grid[nr][nc]==INF){
                        grid[nr][nc]=grid[r][c]+1;
                        q.push({nr,nc});
                    } 
                }
        }     
    }
};
