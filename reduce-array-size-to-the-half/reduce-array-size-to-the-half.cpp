class Solution {
public:
    int minSetSize(vector<int>& arr) {
        
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        map<int,int> m;
        for(auto val: arr)
        {
            m[val]++;
        }
        int sz = arr.size();
        int originalSz = sz;
        int res = 0;
        
        multiset<int,greater <int>> s;  
        for(auto i = m.begin(); i != m.end(); i++)
        {
            s.insert(i->second);
        }   
        
        
        auto i = s.begin();
        while(sz > originalSz/2)
        {
            sz = sz - *i;
            i++;
            res++;
        }
        
        return res;
    }
    
   
};