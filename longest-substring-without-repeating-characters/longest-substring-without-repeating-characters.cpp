class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int sz = s.size();
        int l = 0;
        int r = 0;
        int res = 0;
        
        vector<bool> already(256,false);
        int len = 0;
        while( r < sz )
        {
            while(r < sz && !already[(int)s[r]])
            {
                already[(int)s[r]] = true;
                r++;
                len++;
            }
            
            // cout << "len1: " << len << endl;
            
            
            res = max(res,len);
            
            while( r < sz && already[(int)s[r]])
            {
                
                already[(int)s[l]] = false;
                l++;
                len--;
            }
            // cout << "len2: " << len << endl;
        }
        return res;
    }
};