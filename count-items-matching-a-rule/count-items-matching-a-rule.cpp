class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        
        int res = 0;
        for(auto c: items)
        {
            
            if( (ruleKey == "type" && ruleValue == c[0]) || (ruleKey == "color" && ruleValue == c[1]) || (ruleKey == "name" && ruleValue == c[2]) )
            {
                res++;
                
            }
            
        }
        return res;
            
    }
};