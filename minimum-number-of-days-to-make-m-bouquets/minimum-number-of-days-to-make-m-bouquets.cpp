class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        
        int sz = bloomDay.size();
        if(sz < 1LL*m*k)
        {
            return -1;
        }
        
        
        auto ans = minmax_element(bloomDay.begin(),bloomDay.end());
        int l = *ans.first;
        int r = *ans.second;
        
        
        int ret;
        while(l <= r)
        {
            
            int daysPassed = l + (r-l)/2;
            int flowers = 0;
            int boq = 0;
            for(int i = 0;i < sz; i++)
            {
                if(bloomDay[i] > daysPassed)
                {
                    flowers = 0;
                }else if(++flowers >= k) { // clevar, taken idea from lee
                    boq++; 
                    flowers = 0;
                }
            }
            
            if(boq >= m )
            {
                ret = daysPassed;
                r = daysPassed-1;
            }else{
                l = daysPassed+1;
            }
            
            
        }
        
        return ret;
        
        
    }
    
    
};