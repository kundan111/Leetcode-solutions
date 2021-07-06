class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int,int> m;
        for(auto val: arr)
        {
            m[val]++;
        }
        int sz = arr.size();
        int originalSz = sz;
        int res = 0;
        
        vector<pair<int,int>> t;
        for(auto i = m.begin(); i != m.end(); i++)
        {
            t.push_back(make_pair(i->first,i->second));
        }   
        
        sort(t.begin(),t.end(),comparator);
        
        auto i = 0;
        while(sz > originalSz/2)
        {
            sz = sz - t[i].second;
            i++;
            res++;
        }
        
        return res;
    }
    
    static bool comparator(pair<int,int> a , pair<int,int> b)
    {
        return a.second > b.second;
        
    }
};