class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        
        unordered_map<int,int>m;
        for(int val:arr)
        {
            m[val]++;
        }
        int sz = m.size();
        unordered_set<int> s;
        for(auto i = m.begin(); i != m.end(); i++)
        {
            if(s.find(i->second) != s.end())
            {
                return false;
            }
            s.insert(i->second);
        }
        
        return sz == s.size();
    }
};