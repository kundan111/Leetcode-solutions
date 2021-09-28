class Solution {
public:
    int countGoodSubstrings(string s) {
     
        if(s.size() < 3)
        {
            return 0;
        }
        
        int res = 0;
        int sz = s.size();
        
        unordered_map<char, int>m;
        
        int i = 0;
        while(i < 3)
        {
            m[s[i]]++;
            i++;
        }
        
        res = m.size() == 3 ?  1 : 0;
        
        int j = 0;
        while(i < sz)
        {
            m[s[i]]++;
            m[s[j]]--;
            
            if(m[s[j]] == 0)
            {
                m.erase(s[j]);
            }
            
            
            // cout << "i: " << i << " j: " << j << " res: " << res << endl;
                
           
            res += m.size() == 3 ?  1 : 0;
            
            i++;
            j++;
            
        }
        
        
        return res;
        
        
        
        
        
    }
};