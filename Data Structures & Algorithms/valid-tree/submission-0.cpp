class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        //Time=O(V+E) ;space=O(V)
        vector<vector<int>> adj(n);
        vector<int> visited(n,false);
        int count=1;
        //unordered_map<int,vector<int>> preMap;
        for(const auto& edge: edges){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);//unindirected
            adj[v].push_back(u);
        }
        auto dfs = [&](auto self,int u)->void{
            visited[u]=true;
            for(int v: adj[u]){
                if(!visited[v]) {
                    self(self,v);
                    count++;
                }
            }
        };

        if(edges.size()!=n-1) return false;
        dfs(dfs,0);
        return count==n;
    }
};
