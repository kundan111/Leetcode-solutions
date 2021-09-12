class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rt) {
        sort(rt.begin(),rt.end(),com);
        int sz = rt.size();
        
        
        long long int res = 0;
        
        for(int i = 0; i < sz-1; i++)
        {
            int l = i+1;
            int r = sz-1;
            int curW = rt[i][0];
            int curH = rt[i][1];
            int temp = 0;
            while(l <= r)
            {
                
                int mid = l + (r-l)/2;
                int midW = rt[mid][0];
                int midH = rt[mid][1];
                
                long long int a = (1LL)*curW*midH;
                long long int b = (1LL)*midW*curH;
                
                if(a == b)
                {
                    temp += (mid-l+1);
                    l = mid+1;
                    
                }else if(a < b)
                {
                    r = mid-1;   
                }else{
                    l = mid+1;
                }
            }
            
            res += temp;
            
            
            
        }
        
        return res;
        
    }
    
    
    static bool com(vector<int>&a,vector<int>&b)
    {
        return (1LL)*a[0]*b[1] <  (1LL)*b[0]*a[1];
    }
};