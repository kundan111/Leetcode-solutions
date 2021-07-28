class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for(int i = left; i <= right; i++)
        {
            if(isSelfDividing(i) && i % 10 != 0)
            {
                res.push_back(i);
            }
        }
        
        
        return res;
    }
    
    bool isSelfDividing(int val)
    {
        
        int ori = val;
        while(val)
        {
            int last = val%10;
            val = val/10;
            if(!last || ori % last != 0)
            {
                return false;
            }
        }
        
        return true;
    }
};