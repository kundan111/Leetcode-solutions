class Solution {
public:
    int minStoneSum(vector<int>& p, int k) {
        priority_queue<int>pq(p.begin(),p.end());
        while(k)
        {
            int max = pq.top();
            pq.pop();
            pq.push(max - floor(max/2));
            k--;
        }
        
        int res = 0;
        while(!pq.empty())
        {
            res = res + pq.top();
            pq.pop();
        }
        return res;
        
    }
};