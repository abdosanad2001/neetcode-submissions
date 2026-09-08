class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int R=grid.size(),C=grid[0].size();
        vector<vector<bool>> visited(R,vector<bool>(C,false));
        int dr[]={-1,1,0,0},dc[]={0,0,-1,1};
        int islands=0;

        auto bfs=[&] (int startR,int startC){
            queue<pair<int,int>> q;
            q.push({startR,startC});
            visited[startR][startC]=true;

            while(!q.empty()){
                auto [r,c]=q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int nr=r+dr[i];
                    int nc=c+dc[i];
                    if(nr>=0 && nr<R && nc>=0 && nc<C
                    && !visited[nr][nc] && grid[nr][nc]=='1'){
                        visited[nr][nc]=true;
                        q.push({nr,nc});
                    }
                }
            }
        };

        for(int r=0;r<R;r++){
            for(int c=0;c<C;c++){
                if(!visited[r][c] && grid[r][c]=='1'){
                    islands++;
                    bfs(r,c); 
                }
            }
        }
        return islands;
    }
};
