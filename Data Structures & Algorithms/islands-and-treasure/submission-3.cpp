class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        //Time=O(n*m);space=O(n*m)
        const int INF=2147483647;
        int R=grid.size(),C=grid[0].size();
        int dr[]={-1,1,0,0},dc[]={0,0,-1,1};


        auto bfs =[&](){
            queue<pair<int,int>> q;
            for(int r=0;r,r<R;r++){
                for(int c=0;c<C;c++){
                    if(grid[r][c]==0)
                    q.push({r,c});
                }
            }
            
            int levels=1;
            while(!q.empty()){
                int sz=q.size();
                for(int k=0;k<sz;k++){
                    auto [r,c]=q.front();
                q.pop();

                for(int i=0;i<4;i++){
                    int nr=r+dr[i],nc=c+dc[i];
                    if(nr>=0 && nr<R && nc>=0 && nc<C
                     && grid[nr][nc]==INF){
                        grid[nr][nc]=levels;
                        q.push({nr,nc});
                        
                    }

                }
                
                }
                
                levels++;
            }
            
        };
        bfs();

        
    }
};
