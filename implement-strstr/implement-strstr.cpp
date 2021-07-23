class Solution {
public:
    int strStr(string h, string n) {
        if(n == "")
            return 0;
        if(n.size() > h.size())
            return -1;
        int sz = h.size();
        int nz = n.size();
        for(int i = 0; i < sz;i++)
        {
            int j = i;
            if(h[i] == n[0])
            {
                int p = 0;
                while(p < nz && j < sz && h[j] == n[p])
                {
                    j++;
                    p++;
                }
                // if((j == sz && h[j-1] == n[j-1]) || (j < sz && h[j] == n[p-1]))
                if( p == nz)    
                {
                    return i;
                }
            // i = j;
            }
            // else{
            //     i++;
            // }
            
        }
        
        return -1;
    }
};