class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
    
        int l = *max_element(weights.begin(),weights.end());
        int r = accumulate(weights.begin(),weights.end(),0);
        
        return bs(weights,l,r,days);
        
    }
    
    int bs(vector<int>& weights, int l, int r,int days)
    {
        
         // search for first true
        int ret;
        while(l <= r)
        {
            int mid = l + (r-l)/2;
            if(ifItisSufficient(weights,mid,days))
            {
                ret = mid;
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        return ret;
        
    }
    
    bool ifItisSufficient(vector<int>& w,int val, int &targetDays)
    {
        int i = 0;
        int sz = w.size();
        int days = 0;
        
        while(i < sz)
        {
            int curSum = 0;
            int j = i;
            while(j < sz && curSum + w[j] <= val)
            {
                curSum += w[j];
                j++;
            }
            
            i = j;
            days++;
        }
        
        return days <= targetDays;
    }
    
    
};