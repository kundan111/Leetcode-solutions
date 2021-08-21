class Solution {
public:
    int minTimeToType(string word) {
        int res = 0;
        char prev = 'a';
        for(char c: word)
        {
            
            int movetime = min(26-abs(c-prev),abs(c-prev));
            int typetime = 1;
            prev = c;
            
            res = res + movetime + typetime;
        }
        
        return res;
    }
};