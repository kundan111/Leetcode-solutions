class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<string,vector<string>, comp>pq(nums.begin(),nums.end());
        
        k--;
        while(k)
        {
            pq.pop();
            k--;
        }
        
        return pq.top();
    }
    
    struct comp {
    
       bool operator()(string a,string b)
        {
            
           return a.size() == b.size() ? (a < b) : (a.size() < b.size());
        }
        
    };
};