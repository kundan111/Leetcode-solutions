class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
     
        long long f = stringToInt(firstWord);
        long long s = stringToInt(secondWord);
        long long t = stringToInt(targetWord);
        
        if(f > 0 && s > 0 && t > 0)
        {
            if(t < f || t < s)
            {
                return false;
            }
        }
        
        return f + s == t;
        
        
    }
    
    long long int stringToInt(string s)
    {
        long long int res = 0;
        string digitString = "";
        
        for(char c: s)
        {
            digitString += to_string(c-'a');
        }
        
        int sz = digitString.size();
        
        res = (digitString[sz-1]-'0')%10;
        
        int i = sz-2;
        
        int j = 1;
        while(i >= 0)
        {
            res = pow(10,j) * (digitString[i] - '0') + res;
            j++;
            i--;
        }
        
        return res;
    }
};