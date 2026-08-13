class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        //T=O(nlogn);space=O(1)
        int n=people.size();
        sort(people.begin(),people.end());
        int l=0,r=n-1;
        int count=0;
        while(l<=r){
            if(people[l]+people[r]<=limit) {
                l++;
                r--;         
            }
            else{
                r--;
            }
            count++;
           
            
        }
        return count;
    }
};