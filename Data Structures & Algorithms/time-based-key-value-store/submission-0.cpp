class TimeMap {
private:
    ////Time=O(Logn);space=O(n)
    unordered_map<string,vector<pair<string,int>>> store;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        store[key].push_back({value,timestamp});
    }
    
    string get(string key, int timestamp) {
        //Time=O(Logn)
        string res="";
        int n=store[key].size();
        int ans=-1;
        int l=0,r=n-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(store[key][mid].second<=timestamp){
                ans=mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        if(ans!=-1) res+=store[key][ans].first;
        return res;
    }
};
