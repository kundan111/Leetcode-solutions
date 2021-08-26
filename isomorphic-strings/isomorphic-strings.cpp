class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int sz = s.size();
        int tz = t.size();
        
        if(sz != tz)
            return false;
        
        map<char,char> m;
        map<char,char>m2;
        for(int i = 0; i < sz; i++)
        {
            char c1 = s[i];
            char c2 = t[i];
            auto itr1 = m2.find(c2);
            if(itr1 != m2.end())
            {
                if(itr1->second != c1)
                {
                    return false;
                }
            }else{
                m2[c2] = c1;
            }
            
            
            
            auto itr = m.find(c1);
            if( itr != m.end())
            {
                if(itr->second != c2)
                {
                    return false;
                }
            }else{
                
                
                m[c1] = c2;
                
            }
        }
        
        
        for(auto v: m)
        {
            cout << v.first << " -> " << v.second << endl;
        }        
        
        
        
        return true;
    }
};