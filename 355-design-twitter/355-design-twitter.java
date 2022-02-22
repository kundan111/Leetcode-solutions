class Twitter {

    int recentCounter = 0;
    class PostObj implements Comparable<PostObj>{
        
        int tweetId;
        int time;
        public PostObj(int tweetId) {
            this.tweetId = tweetId;
            time = ++recentCounter;
        }
        @Override
        public int compareTo(PostObj o) {

            return -1*(this.time - o.time);
        }
        

    }
    
    
    HashMap<Integer,ArrayList<Integer>> followMap = new HashMap<>();
    HashMap<Integer,ArrayList<PostObj>> feed = new HashMap<>();

    public Twitter() {
    }
    
    public void postTweet(int userId, int tweetId) {
        if(feed.containsKey(userId))
        {
            ArrayList<PostObj> existing = feed.get(userId);
            existing.add(new PostObj(tweetId));
            feed.put(userId, existing);
        }else{
            ArrayList<PostObj> newTemp = new ArrayList<>();
            newTemp.add( new PostObj(tweetId));
            feed.put(userId, newTemp);
        }
    }
    
    public List<Integer> getNewsFeed(int userId) {
        
        PriorityQueue<PostObj> feedQueue = new PriorityQueue<>();
        
        if(feed.containsKey(userId))
        {
            feedQueue.addAll(feed.get(userId));
        }

        if(followMap.containsKey(userId))
        {
            for (Integer followerId : followMap.get(userId)) {
                if(followerId != null && feed.containsKey(followerId))
                {
                    feedQueue.addAll(feed.get(followerId));
                }
            }

        }


        List<Integer> res = new ArrayList<>();
        int counter = 0;
        while (counter < 10 && feedQueue.size() > 0 ) {
            res.add(feedQueue.poll().tweetId);
            counter++;
        }

        feedQueue.clear();

        return res;
    }
    
    public void follow(int followerId, int followeeId) {
        if(followMap.containsKey(followerId))
        {
            ArrayList<Integer> followersList = followMap.get(followerId);
            
            for (Integer followee : followersList) {
                if (followeeId == followee) {
                    return;
                }
            }
            
            followersList.add(followeeId);
            followMap.put(followerId , followersList);
        }else{
            ArrayList<Integer> newFollowersList = new ArrayList<>();
            newFollowersList.add(followeeId);
            followMap.put(followerId, newFollowersList);
        }
        
    }
    
    
    
    public void unfollow(int followerId, int followeeId) {
        
        if(!followMap.containsKey(followerId))
        {
            return;
        }
        
        for (int followee : followMap.get(followerId)) {
            if(followee == followeeId)
            {
                followMap.get(followerId).remove((Integer)followeeId);
                return;
            }    
        }
        
        
        
    }
}


/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * List<Integer> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */