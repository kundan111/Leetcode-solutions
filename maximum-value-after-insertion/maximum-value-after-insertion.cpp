class Solution {
public:
    string maxValue(string n, int x) {
        bool isNeg = n[0] == '-';
        
        int f = -1;
        int s = -1;
        int sz = n.size();
        bool f1 = true, f2 = true;
        for(int i = 0; i < sz; i++)
        {
            if(isNeg && i != 0 && n[i]-'0' > x && f1)
            {
               f = i;
               f1 = false;
            }
            
            if(n[i]-'0' < x && f2)
            {
               s = i;
               f2 = false;
            }
        }
        
        if(isNeg)
        {
            if(f == -1)
            {
                f = sz;
            }
            n.insert(n.begin()+f,(char)(48+x));
        }else{
            
            if(s == -1)
            {
                s = sz;
            }
            
            n.insert(n.begin()+s,(char)(48+x));
        }
        
        
        
        return n;
    }
};