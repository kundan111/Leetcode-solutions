class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        int f = convert(firstWord);
        int s = convert(secondWord);
        int t = convert(targetWord);
        
        return f+s == t;
    }
    
    int convert(string s)
    {
        int res = 0;
        for(char c: s)
        {
            res = res*10 + (c-'a');
        }
        
        return res;
    }
    
    
    
};