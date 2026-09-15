class Solution {
public:
    
    int minEatingSpeed(vector<int>& piles, int h) {
        //N=piles.size(),M=max(piles)
        //Time=O(NlogM)
        auto check=[&](int mid)->bool{
            long long total_hours=0;
            for(int p: piles){
                total_hours+=ceil((double)p/mid);
            }
            return total_hours<=h;
        };
       
        int l=1,r=*max_element(piles.begin(),piles.end()),ans=r;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(check(mid)){
                r=mid-1;
                ans=mid;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};
