class Solution {
public:
//  Time = O(n); Space = O(n) 
    int numIslands(vector<vector<char>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        auto visited=vector(rows, vector(cols,false));
        int islands=0;
        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};

        auto bfs=[&](int startR,int startC){
            queue<pair<int,int>> q;
            q.push({startR,startC});
            visited[startR][startC]=true;

            while(!q.empty()){
                auto [r,c]=q.front();
                q.pop();

                for(int i=0;i<4;i++){
                    int nr=dr[i]+r;
                    int nc=dc[i]+c;
                
                if(nr>=0 && nr<rows && nc>=0 && nc<cols 
                && !visited[nr][nc]
                && grid[nr][nc]=='1'){
                    visited[nr][nc]=true;
                    q.push({nr,nc});
                }
            }
        }
    };

        for(int r=0;r<rows;r++){
            for(int c=0;c<cols;c++){
                if(grid[r][c]=='1' && !visited[r][c]){
                    islands++;
                    bfs(r,c);
                }
            }

        }
        return islands;


       

       
    }
};
