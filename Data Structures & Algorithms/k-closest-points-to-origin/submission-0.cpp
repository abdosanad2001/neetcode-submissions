class Solution {
public:
    //Time=O(Nlogk);space=O(k)
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {    
        priority_queue<pair<int,vector<int>>> max_heap;
        for(int i=0;i<points.size();i++){
            int x=points[i][0];
            int y=points[i][1];
            int d=pow(x,2)+pow(y,2);
            max_heap.push({d,{x,y}});

        }
        while(max_heap.size()>k){
            max_heap.pop();
        }
        vector<vector<int>> v;
        while(!max_heap.empty()){
            v.push_back(max_heap.top().second);
            max_heap.pop();
        }
        return v;
        
    }
};
