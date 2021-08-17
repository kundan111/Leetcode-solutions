class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sz = s.size();
        int tz = t.size();
        
        int j = 0;
        for(int i = 0; i < tz; i++)
        {
            if(t[i] == s[j])
                j++;
        }
        
        return j == sz;
    }
    
};