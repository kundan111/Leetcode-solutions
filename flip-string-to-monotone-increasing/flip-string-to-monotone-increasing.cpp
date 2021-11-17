class Solution {
public:
    int minFlipsMonoIncr(string s) {
        
        int ans = 0;
        int sz = s.size();
        int totOnes = count(s.begin(),s.end(), '1');
        ans = min(totOnes,sz-totOnes);
        
        int oneCount = 0;
        for(int i = 0; i < sz; i++)
        {
            if(s[i] == '1')
            {
                oneCount++;
            }
            
            
            int zeroCountinLeftPart = (sz - i-1) - (totOnes - oneCount);
            // cout << "zeroCountinLeftPart: " << zeroCountinLeftPart << endl;
            
            ans = min(ans,oneCount + zeroCountinLeftPart);
            
        }
        return ans;
    }
    
    int zeroCounter(string &s, int i)
    {
        int res = 0;
        for(int j = i; j < s.size(); j++)
        {
            if(s[j] == '0')
            {
                res++;
            }
        }
        
        
        return res;
            
    }
};