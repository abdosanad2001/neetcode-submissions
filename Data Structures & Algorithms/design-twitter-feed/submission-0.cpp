class Twitter {
private:
    unordered_map<int,vector<pair<int,int>>> myMap;
    unordered_map<int,unordered_set<int>> following;
    int time=0;
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        myMap[userId].push_back({time,tweetId});
        time++;
        
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> feed;
        priority_queue<pair<int,int>> max_heap;
        if (myMap.find(userId) != myMap.end()) {
            for (auto& tweet : myMap[userId]) {
                max_heap.push(tweet);
            }
        }
        if (following.find(userId) != following.end()) {
            for (int followeeId : following[userId]) {
                if (myMap.find(followeeId) != myMap.end()) {
                    for (auto& tweet : myMap[followeeId]) {
                max_heap.push(tweet);
                    }
                }
            }
        }

        
        while(!max_heap.empty() && feed.size()<10){
            feed.push_back(max_heap.top().second);
            max_heap.pop();
        }
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);//O(1)
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);//O(1) 
    }
};
