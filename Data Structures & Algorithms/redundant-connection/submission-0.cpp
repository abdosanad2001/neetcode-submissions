class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        //Time=O((E+V)*E);space=O(E+V)
        int n=edges.size();
        vector<vector<int>> adj(n+1);
        for(const auto& edge:edges){
            int u=edge[0];
            int v=edge[1];

        vector<bool> visited(n+1,false);
        auto dfs=[&](auto self,int u)->bool{
           if(u==v) return true;
           visited[u]=true;
           for(int v: adj[u]){
            if(!visited[v]) {
                visited[v]=true;
                if(self(self,v)) return true;
                }
           }
           return false;
           
        };

        if(dfs(dfs,u)) return {u,v};
        adj[u].push_back(v);
        adj[v].push_back(u);
        
        }
        return {};
    }
};
