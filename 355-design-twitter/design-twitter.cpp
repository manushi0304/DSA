class Twitter {
private:
    int timeStamp;
    unordered_map<int, unordered_set<int>>follows;
    unordered_map<int, vector<pair<int,int>>>tweets;
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
          tweets[userId].push_back({timeStamp++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>> pq;
        
        // include self tweets
        if (tweets.count(userId)) {
            for (auto &tw : tweets[userId]) {
                pq.push(tw);
            }
        }
        
        // include followees' tweets
        for (int followee : follows[userId]) {
            if (tweets.count(followee)) {
                for (auto &tw : tweets[followee]) {
                    pq.push(tw);
                }
            }
        }
        
        // collect up to 10 most recent tweets
        vector<int> res;
        int cnt = 0;
        while (!pq.empty() && cnt < 10) {
            res.push_back(pq.top().second);
            pq.pop();
            cnt++;
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return; 
        follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (follows[followerId].count(followeeId)) {
            follows[followerId].erase(followeeId);
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */