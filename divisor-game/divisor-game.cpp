class Solution {
public:
    
    bool divisorGame(int n) {
        vector<int> v(n+1,-1);
        return divisorGameUtil(n,v);
    }
    
    
    bool divisorGameUtil(int n, vector<int> &v) {
        if(n == 1)
            return false;
        for(int i =1; i*i <= n; i++)
        {
            
            
            if(n%i == 0)
            {
                if(v[n-i] != -1)
                {
                    return v[i];
                }
                
                if(!divisorGameUtil(n-i,v))
                {
                    v[n-i] = false;
                    return v[i] = true;
                }
                    
            }
            if(i != 1 && n%i == 0 && n/i != i)
            {
                if(v[n-(n/i)] != -1)
                {
                    return v[n-(n/i)];
                    
                }
                
                if(!divisorGameUtil(n-(n/i) , v))
                {
                    v[n-(n/i)] = false;
                    return v[(n/i)] = true;
                }
                    
            }
        }
    return false;
    }
    
    
    
    
};