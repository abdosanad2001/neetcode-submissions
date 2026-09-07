class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //Time=O(V+E);space=O(V+E)
        unordered_map<int,vector<int>> preMap;
        unordered_set<int> visited;
        //check if there is any cycle
        for(const auto& edge: prerequisites){
            int course=edge[0];
            int pre=edge[1];
            preMap[course].push_back(pre);
        }
        auto dfs = [&](auto self ,int u)->bool{
            if(preMap[u].empty()) return true;
            visited.insert(u);
            for(int pre: preMap[u]){
                if(visited.count(pre)) return false;
                if(!self(self,pre)) return false;;
            }
            visited.erase(u);
            preMap[u].clear();
            return true;
        };

        for(int crs=0;crs<numCourses;crs++){
            if(!dfs(dfs,crs)){
                return false;
            };
        }
        return true;
    }
};
