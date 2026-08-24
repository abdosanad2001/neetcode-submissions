class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        //Time=O(n*m) || space=O(n*m)
        //where n=grid.size() && m=grid[0].size()

        int rows=grid.size(),cols=grid[0].size();
        auto visited=vector(rows, vector<bool>(cols,false));
        int dr[]={-1,1,0,0},dc[]={0,0,-1,1};
        int maxArea=0;

        


        auto bfs = [&](int startR, int startC){
            queue<pair<int,int>> q;
            int area=1;
            visited[startR][startC]=true;
            q.push({startR,startC});
            while(!q.empty()){
            auto[r,c]=q.front();
            q.pop();
            for(int i=0;i<4;i++){
            int nr=dr[i]+r;
            int nc=dc[i]+c;
            if(nr>=0 && nr<rows && nc>=0 && nc<cols 
                && grid[nr][nc]==1 
                && !visited[nr][nc]){
                    visited[nr][nc]=true;
                    q.push({nr,nc});
                    area++;
                }
            
            }
        }
        maxArea=max(maxArea,area);

        };

        for(int r=0;r<rows;r++){
            for(int c=0;c<cols;c++){
                if(grid[r][c]==1  && !visited[r][c]){
                    visited[r][c]=true;
                    bfs(r,c);
                }
            }
        }
        return maxArea;

        
    }
};
