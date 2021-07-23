class Solution {
public:
    bool isLongPressedName(string n, string t) {
        
        if(n.size() > t.size())
            return false;
        
        int nz = n.size();
        int tz = t.size();
    
        if(t[0] != n[0])
            return false;
        
        int i = 0;
        int j = 0;
        while( i  < nz )
        {
            if(j < tz && n[i] == t[j])
            {
                j++;
                if( i + 1 < nz && n[i+1] == t[j])
                {
                    i++;
                }
                
            }else{
                i++;
                if(n[i] != t[j])
                {
                    return false;
                }
            }
        }
        
        return true;
        
    }
};