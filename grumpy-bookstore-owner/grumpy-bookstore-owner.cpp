class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        
        int sz = customers.size();
        
        int count = 0;
        for(int i = 0; i < minutes; i++)
        {
            if(customers[i] && grumpy[i])
            {
                count += customers[i];
            }
        }
        
        int maxLen = count;
        
        int l = 0;
        int r = minutes-1;
        
        int finalL = l;
        int finalR = r;
        
        
        while(r < sz)
        {
            if(customers[l] && grumpy[l])
            {
                count -= customers[l];
            }
            r++;
            if(r < sz && (customers[r] && grumpy[r]))
            {
                count += customers[r];
            }
            
            // cout << "Count: " << count << endl;
            
            if(count > maxLen)
            {
                maxLen = count;
                finalL = l+1;
                finalR = r;
            }
            
            l++;
            
        }
        
        
        // cout << "maxLen: " << maxLen << endl << "finalL: " << finalL << endl << "finalR: " << finalR << endl;
        
        
        
        // return maxLen;
        
        
    
    
    int res = 0;
    for(int i = 0; i < finalL; i++)
    {
        if(grumpy[i] == 0)
        {
            res += customers[i];
        }
    }
    
    for(int i = finalR+1; i < sz; i++)
    {
        if(grumpy[i] == 0)
        {
            res += customers[i];
        }
    }
    
    for(int i = finalL; i <= finalR; i++)
    {
        
        res += customers[i];
        
    }
    
    return res;
        
        }
    
    
};