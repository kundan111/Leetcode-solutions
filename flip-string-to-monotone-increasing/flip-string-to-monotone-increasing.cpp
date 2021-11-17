class Solution {
public:
    int minFlipsMonoIncr(string s) {
        
        int flipCount = 0;
        int oneCount = 0;
        
        for(char c : s)
        {
            if(c == '1')
            {
                oneCount++;
            }else{
                flipCount++;
            }
            
            flipCount = min(flipCount,oneCount);
        }
        
        return flipCount;
        
    }
};