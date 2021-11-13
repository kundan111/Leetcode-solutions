class Solution {
public:
    int connectSticks(vector<int>& sticks) {
     
        priority_queue<int, vector<int>, greater<int> > minHeap(sticks.begin(),sticks.end());
        int sz = sticks.size();
        
        if(sz < 2)
        {
            return 0;
        }
        
        int res = 0;
        while(minHeap.size() >= 2)
        {
                int min1 = minHeap.top();
                minHeap.pop();
                int min2 = minHeap.top();
                minHeap.pop();
            
                int val = (min1 + min2);
                minHeap.push(val);
                res += val;
            
        }
        
        // if(minHeap.size())
        // {
        //     res += minHeap.top();
        //     minHeap.pop();
        // }
        
        return res;
    }
};