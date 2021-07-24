class Solution {
public:
    bool areOccurrencesEqual(string s) {
        
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        
        unordered_map<char,int> m;
        for(char c: s)
        {
            m[c]++;
        }
        
        
        auto i = m.begin();
        
        int commVal = i->second;
        
        
        for(; i != m.end(); i++)
        {
            if(commVal != i->second)
            {
                return false;
            }
        }
        
        return true;
    }
};