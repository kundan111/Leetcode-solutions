class Solution {
private:
    vector<bool>selected;
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int sz = changed.size();
        if(sz & 1)
        {
            // size is odd
            return {};
        }
        
        long long int sum = (1LL)*accumulate(changed.begin(),changed.end(),0*1LL);
        if(sum != 0 && sum%3 != 0)
        {
            return {};
        }
        vector<int>res;
        
        
        if(sum == 0)
        {
            vector<int> temp(changed.begin(),changed.begin() + sz/2);
            return temp;
            
        }
        
        sort(changed.begin(),changed.end());
        
        selected.resize(sz,false);
        
        for(int i = 0; i < sz-1; i++)
        {
           if(!selected[i])
           {
               selected[i] = true;
               int indx = bs(changed,i+1,sz-1,2LL*changed[i]);
               
               if(2LL*changed[i] > 100000)
               {
                   return {};
               }
               
               if(indx == -1)
                  {
                   // cout << 2*changed[i] << " not found!" << endl;
                    return {};   
                  }else{
                      res.push_back(changed[i]);
                      selected[indx] = true;
                  }
           }
            
           
        }
        
        return res;
    }
    
    int bs(vector<int>& changed, int l, int r, long long int target)
    {
        int ret = -1;
        while(l <= r)
        {
            long long int mid =  l + (r-l)/2;
            int curVal = changed[mid];
            
            if(curVal == target && !selected[mid])
            {
                ret = mid;
                r = mid-1;
            }else if(curVal > target)
            {
                r = mid-1;
            }else{
                l = mid+1;
            }
            
        }
        
        return ret;
    }
};