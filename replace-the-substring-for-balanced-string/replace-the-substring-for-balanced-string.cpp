class Solution {
public:
    int balancedString(string s) {
            
        unordered_map<char,int>m
        {
            {'Q',0},
            {'W',0},
            {'E',0},
            {'R',0},
        };
        
        for(char &c: s)
        {
            m[c]++;
        }
        
        int sz = s.size();
        int optimalCount = sz/4;
        
        bool _isBalanced = true;
        for(auto val : m)
        {
            if(val.second != optimalCount)
            {
                _isBalanced = false;
                break;
            }
        }
        
        if(_isBalanced)
        {
            return 0;
        }
        
        int l = 0;
        int r = 0;
        
        int res = sz;
        
        while(r < sz)
        {
            m[s[r]]--;
            if(isBalanced(m,optimalCount))
            {
                res = min(res,r-l+1);
                while(l <= r)
                {
                    m[s[l]]++;
                    l++;
                    if(isBalanced(m,optimalCount))
                    {
                        res = min(res,r-l+1);
                            
                    }else{
                        break;
                    }
                }
            }
            r++;
        }
        
        return res;
        
    }
    
    bool isBalanced(unordered_map<char,int> &m, int optimalCount)
    {
        for(auto val : m)
        {
            if(val.second > optimalCount)
            {
                return false;
            }
        }
        return true;
    }
};