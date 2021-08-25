class Solution {
public:
    int numSplits(string s) {
        unordered_map<char,int> m1,m2;
        int res = 0;
        int sz = s.size();
        if(sz == 1)
            return 0;
        
        m1[s[0]]++;
        for(int i = 1; i < sz ; i++)
        {
            m2[s[i]]++;
        }
        
        if(m1.size() == m2.size())
        {
            res++;
        }
        
        for(int i = 1; i < sz-1 ; i++)
        {
            if(m1.size() == m2.size())
            {
                res++;
            }
            m1[s[i]]++;
            m2[s[i]]--;
            // cout << "res: " << res << endl;
            if(m2[s[i]] == 0)
            {
                m2.erase(s[i]);
            }
            
        }
        
        return res;
    }
};