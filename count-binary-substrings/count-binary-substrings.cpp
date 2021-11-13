class Solution {
public:
    int countBinarySubstrings(string s) {
        
        int res = 0;
        int sz = s.size();
        int i = 0;
        
        int prev_1 = 0;
        int prev_2 = 0;
        vector<int> temp;
        while(i < sz)
        {
            int count = 0;
            char cur = s[i];
            while(i < sz && s[i] == cur)
            {
                count++;
                i++;
            }
            temp.push_back(count);
            
        }
    
        if(temp.size() < 2)
        {
            return 0;
        }
        
        
        int l = 0;
        int r = 1;
        
        sz = temp.size();
        
        while(r < sz)
        {
            res += min(temp[l],temp[r]);
            l++;
            r++;
        }
        
        return res;
    }
    
    
    char opposite(char c)
    {
        return c == '0' ? '1' : '0';
    }
};