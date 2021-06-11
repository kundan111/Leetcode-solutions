class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>arr(26,0);
        int i = 0;
        int sz_s  = s.size();
        int sz_t  = t.size();
        
        while(i < sz_s)
        {
            arr[s[i] - 97]++;
            i++;
        }
        
        i = 0;
        
        while(i < sz_t)
        {
            arr[t[i] - 97]--;
            
            if(arr[t[i] - 97] < 0)
            {
                return false;
            }
            
            i++;
        }
        
        i = 0;
        while(i < 26)
        {
            if(arr[i] != 0)
                return false;
            
            i++;
        }
        
        return true;
        
        
            
    }
};