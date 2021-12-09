class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        vector<vector<int>> v;
        unordered_map<int,int>m;
        for(int val : nums)
        {
            m[val]++;
        }
        
        for(auto val : m)
        {
            v.push_back({val.first,val.second});
        }
        
        sort(v.begin(),v.end(), [](auto a, auto b){
            return a[1] > b[1];
        });
        
        vector<int> res;
        
        int i = 0;
        while(k--)
        {
            res.push_back(v[i][0]);
            i++;
        }
        
        return res;
        
    }
    
    bool static comp(vector<int> a , vector<int> b)
    {
        return a[1] < b[1];
    }
};