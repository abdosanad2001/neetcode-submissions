class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        //T=O(E+V); space=O(E+V)
        vector<vector<int>> adj(n);
        vector<bool> visited(n,false);
        for(const auto& edge: edges){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        auto dfs=[&](auto self,int u)->void{
            visited[u]=true;
            for(int v: adj[u]){
                if(!visited[v]) {
                self(self,v);
            }
            }
            

        };
        int comp=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                comp++;
                dfs(dfs,i);
                
            }
        }
        return comp;

    }
};
