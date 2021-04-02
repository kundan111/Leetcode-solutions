class Solution {
public:
    bool isPalindrome(int x) {
        //convert to string
        string converted = to_string(x);
        int sz = converted.size();
        
        // size id odd
        //0123456
        //abcdcda -> size = 7
        // size/2 = 3
        
        //size is even 
        //0123
        //abba -> size = 4
        // size/2 = 2
        
        if(sz == 1)
            return true;
        
        if(sz == 2)
        {
            return converted[0] == converted[1];
        }
        
        
        // all the string having length >= 3
        bool returnValue = true;
        for(int i = 0; i < sz/2; i++)
        {
            if(converted[i] != converted[sz-1-i])
            {
                returnValue = false;
                break;
            }
        }
        
        
        return returnValue;
        
    }
};