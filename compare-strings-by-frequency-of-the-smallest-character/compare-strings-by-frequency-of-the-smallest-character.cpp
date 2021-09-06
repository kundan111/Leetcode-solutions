class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> freqCount;
        for(string &s: words)
        {
            freqCount.push_back(fun(s));
        }
        vector<int> res;
        for(string &s: queries)
        {
            int cur = fun(s);
            int curVal = 0;
            for(int val : freqCount)
            {
                if(cur < val)
                {
                    curVal++;
                }
            }
            
            res.push_back(curVal);
        }
        
        return res;
    }
    
    int fun(string s)
    {
        int count = 0;
        char mn = '{';
        for(char &c: s)
        {
            if(c < mn)
            {
                mn = c;
                count = 1;
            }else if(c == mn){
                count++;
            }
        }
        
        return count;
    }
};