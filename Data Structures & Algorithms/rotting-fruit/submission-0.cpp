class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        //Time=O(R*C);space=O(R*C)
        int R=grid.size(),C=grid[0].size();
        int dr[]={-1,1,0,0},dc[]={0,0,-1,1};
        

        auto bfs=[&]()->int{
            queue<pair<int,int>> q;
            vector<vector<bool>> visited(R,vector<bool>(C,false));
            int fresh=0;
            for(int r=0;r<R;r++){
                for(int c=0;c<C;c++){
                    if(grid[r][c]==2) q.push({r,c});
                    else if(grid[r][c]==1) fresh++;
                }
            }
            if(fresh==0) return 0;
            int minutes=0;
            while(!q.empty() && fresh>0){
                    int sz=q.size();
                    for(int k=0;k<sz;k++){
                    auto [r,c]=q.front();
                    q.pop();

                    for(int i=0;i<4;i++){
                        int nr=r+dr[i],nc=c+dc[i];
                        if(nr>=0 && nr<R && nc>=0 && nc<C && 
                        grid[nr][nc]==1 && !visited[nr][nc]){
                            visited[nr][nc]=true;
                            fresh--;
                            q.push({nr,nc});
                        }
                    }
                  }
                  minutes++;

                }


            return (fresh==0)?minutes :-1;
            
        };
        return bfs();
    }
};
