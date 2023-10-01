class Twitter {
public:
    vector<pair<int, int>> post;
    map<int, vector<int>> following;
    int size_post;

    Twitter() {
        vector<pair<int, int>> post;
        map<int, vector<int>> following;        
    }
    
    void postTweet(int userId, int tweetId) {
        post.push_back(pair<int, int> (userId, tweetId));
        size_post = post.size();
    }
    
    vector<int> getNewsFeed(int userId) {
        int ind = size_post-1;
        vector<int> followees = following[userId];
        vector<int> output;
        while(ind >= 0 & output.size() < 10) {
            if(post[ind].first == userId || find(followees.begin(), followees.end(), post[ind].first) != followees.end()) {
                output.push_back(post[ind].second);
            }
            ind -= 1;
        }
        return output;
        
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].push_back(followeeId);
        
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(remove(following[followerId].begin(), following[followerId].end(), followeeId), following[followerId].end());
        
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