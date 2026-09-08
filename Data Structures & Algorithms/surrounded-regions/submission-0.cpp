class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int R=board.size();
        int C=board[0].size();
        vector<vector<bool>> visited(R,vector<bool>(C,false));
        auto dfs = [&](auto self,int r ,int c){
            if(r<0 ||r>=R ||c<0  ||c>=C ||
            visited[r][c]){
                return;
            }
            visited[r][c]=true;
            if(c-1>=0 && !visited[r][c-1] && board[r][c-1]=='O')
            self(self,r,c-1);
            if(c+1<C && !visited[r][c+1] && board[r][c+1]=='O')
            self(self,r,c+1);
            if(r-1>=0 && !visited[r-1][c] && board[r-1][c]=='O')
            self(self,r-1,c);
            if(r+1<R && !visited[r+1][c] && board[r+1][c]=='O')
            self(self,r+1,c);

        };
        for(int r=0;r<R;r++){
            if(board[r][0]=='O'){
                dfs(dfs,r,0);
            };
            
        }
        for(int r=0;r<R;r++){
            if(board[r][C-1]=='O'){
                dfs(dfs,r,C-1);
            };
            
        }
        for(int c=0;c<C;c++){
            if(board[R-1][c]=='O'){
                dfs(dfs,R-1,c);
            };
            
        }
        for(int c=0;c<C;c++){
            if(board[0][c]=='O'){
                dfs(dfs,0,c);
            };
            
        }
        

        for(int r=0;r<R;r++){
            for(int c=0;c<C;c++){
                if(!visited[r][c] && board[r][c]=='O'){
                    board[r][c]='X';
                }
            }
        }
    }
};
