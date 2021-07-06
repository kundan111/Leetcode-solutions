class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        
        int sz = s1.size();
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        
        int i = 0;
        int f1 = 0;
        int f2 = 0;
        int f3 = 0;
        while(i < sz)
        {
            if(s1[i] - 'a' > s2[i] - 'a')
            {
                f1++;
            }else if(s1[i] - 'a' < s2[i] - 'a')
            {
                f2++;
            }else{
                f3++;
            }
            i++;
        }
        
        if((f1 > 0 && f2 == 0) || (f2 > 0 && f1 == 0))
            return true;
        
        if(f1 == 0 && f2 == 0)
            return true;
        
        
        return false;
        
        
        
        
    }
};