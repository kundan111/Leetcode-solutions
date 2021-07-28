class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>m;
        for(int val:arr)
        {
            m[val]++;
        }
        int sz = m.size();
        set<int>s;
        for(auto i = m.begin(); i != m.end(); i++)
        {
            s.insert(i->second);
        }
        
        return sz == s.size();
    }
};