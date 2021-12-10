class Compare
{
public:
    bool operator() (vector<int> &a , vector<int> &b)
    {
        return a[1] < b[1];
    }
};


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        
        
        unordered_map<int,int>m;
        for(int val : nums)
        {
            m[val]++;
        }
        priority_queue<vector<int>, vector<vector<int>>, Compare > pq;
       
        for(auto val : m)
        {
             
            pq.push({val.first,val.second});
        }
        
        
        
        vector<int> res;
        
        int i = 0;
        while(k--)
        {
            auto _top = pq.top();
            res.push_back(_top[0]);
            pq.pop();
            
            i++;
        }
        
        return res;
        
    }
    
    bool static comp(vector<int> a , vector<int> b)
    {
        return a[1] < b[1];
    }
};