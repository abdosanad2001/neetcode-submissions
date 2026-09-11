class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        //Time=O(n);space=O(n)
        vector<vector<int>> res;
        int n=intervals.size();
        for(int i=0;i<n;i++){
            if(newInterval[1]<intervals[i][0]){
            res.push_back(newInterval);
            while(i<n){
                res.push_back(intervals[i]);
                i++;
            }
            return res;
        }
        else if(newInterval[0]>intervals[i][1]){
            res.push_back(intervals[i]);
        }else{
            newInterval[0]=min(intervals[i][0],newInterval[0]);
            newInterval[1]=max(intervals[i][1],newInterval[1]);
    
        }
        }
        
        res.push_back(newInterval);
        return res;
    }
};
