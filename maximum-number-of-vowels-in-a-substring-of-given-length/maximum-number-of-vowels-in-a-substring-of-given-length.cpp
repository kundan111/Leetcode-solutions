class Solution {
public:
    int maxVowels(string s, int k) {
        
        int sz = s.size();
        
        unordered_map <char,int>m
        {
            {'a', 1},
            {'e', 1},
            {'i', 1},
            {'o', 1},
            {'u', 1},
        };
        
        int vowelCount = 0;
        for(int i = 0; i < k; i++)
        {
            if(m[s[i]])
            {
                vowelCount++;
            }
        }
        int res = vowelCount;
            
        
        int l = 0;
        int r = k-1;
        
        while(r < sz)
        {
            if(m[s[l]])
            {
                vowelCount--;
            }
            r++;
            if(m[s[r]])
            {
                vowelCount++;
            }
            l++;
            
            res = max(res,vowelCount);
        }
        
        return res;
        
    }
};