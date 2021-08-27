class Solution {
public:
    int findKthLargest(vector<int>& v, int k) {
        priority_queue<int> pq(v.begin(),v.end());
        k = k-1;
        while(k--)
        {
            pq.pop();
        }
        
        return pq.top();
    }
};