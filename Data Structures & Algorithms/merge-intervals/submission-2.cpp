class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        vector<vector<int>> res;
        if(n==0) return{{}};
        if(n==1){
            res.push_back(intervals[0]);
            return res;
        }
        res.push_back(intervals[0]);
        int last_end=res[0][1];
        for(int i=1;i<n;i++){

            if(i>1) last_end=res.back()[1];
            if(intervals[i][0]<=last_end){
               res.back()[1]=max(last_end,intervals[i][1]);
            }else{
                res.push_back(intervals[i]);
            }
            
        }
        return res;
    }
};
