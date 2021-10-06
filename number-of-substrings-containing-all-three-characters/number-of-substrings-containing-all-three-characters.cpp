class Solution {
public:
    int numberOfSubstrings(string s) {
        
        int sz = s.size();
        
        vector<int> ct(3,0);
        
        int i = 0;
        int j = 0;
        int res = 0;
        
        while(j < sz)
        {
            ct[s[j]-'a']++;
            while(ct[0] > 0 && ct[1] > 0 && ct[2] > 0 && j > i)
            {
                res += sz-j;
                ct[s[i]-'a']--;
                i++;
            }
            j++;
        }
        
        return res;
        
        
        
        
        
    }
};