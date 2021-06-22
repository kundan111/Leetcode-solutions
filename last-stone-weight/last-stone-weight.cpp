class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue <int> pq;
        
        for(auto i:stones)
        {
            pq.push(i);
        }
        
        if(pq.size() < 2)
        {
            int ret = pq.top();
            pq.pop();
            
            return ret;
        }
        
        while(pq.size() >= 2)
        {
            int firstHeavy = pq.top();
            pq.pop();
            
            int secondHeavy = pq.top();
            pq.pop();
            
            int newEle = abs(firstHeavy-secondHeavy);
            pq.push(newEle);
        }
        
        int ret = pq.top();
            pq.pop();
        
        return ret;
        
        
    }
};