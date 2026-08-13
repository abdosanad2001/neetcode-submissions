class Solution {
public:
    int maxArea(vector<int>& heights) {
        //T=O(n);space=O(1)
        //air=max((r-l)*min(height[l],height[r]))
        int n=heights.size();
        int l=0,r=n-1;
        int max_air=0;
        while(l<r){
            max_air=max((r-l)*min(heights[l],heights[r]),max_air);
            if(heights[l]<heights[r]) l++;
            else r--;
        }
        
        return max_air;
    }
};
