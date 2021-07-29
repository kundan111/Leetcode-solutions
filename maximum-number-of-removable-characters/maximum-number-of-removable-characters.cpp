class Solution {
public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
        string original = s;
        int l = 0;
        int h = removable.size()-1;
        
        
        while(l <= h)
        {
            int mid = l + (h-l)/2;
            
            // replace all characters till mid
            for(int i = 0; i <= mid; i++)
            {
                int indx = removable[i];
                s[indx] = '*';
            }
            
            if(isSubsequence(s,p))
            {
                l = mid+1;
            }else{
                // replace the charaters back
                for(int i = 0; i <= mid; i++)
                {
                    int indx = removable[i];
                    s[indx] = original[indx];
                    
                }
                
                h = mid-1;
            }
        }
        
        return l;
    }
    
    bool isSubsequence(string s,string p)
    {
        int i = 0, j = 0;
        int sz = s.size();
        int pz = p.size();
        
        while(i < sz && j < pz)
        {
            if(s[i] != '*' && s[i] == p[j])
            {
                j++;
            }
            i++;
        }
        
        
        return j == pz;
    }
};